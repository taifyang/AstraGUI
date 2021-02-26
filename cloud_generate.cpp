/**
  *@file cloud_generate.cpp
  *@brief ��������Դ�ļ�
  */


#include "cloud_generate.h"



extern PointCloud::Ptr cloud;
extern PointCloudRGB::Ptr cloudRGB;

extern BlockingConcurrentQueue<cv::Mat> bcq_colorMat;
extern BlockingConcurrentQueue<cv::Mat> bcq_depthMat;
extern BlockingConcurrentQueue<PointCloud::Ptr> bcq_cloud;
extern BlockingConcurrentQueue<PointCloudRGB::Ptr> bcq_cloudRGB;


void Cloud_Generate::run()
{
    float camera_factor, camera_cx, camera_cy, camera_fx, camera_fy; //����ڲ�
    cv::Mat colorMat, depthMat;

    while(true)
    {
        if(bcq_depthMat.try_dequeue(depthMat))
        {
            if(Camera_Settings::depth_resolution == "640*480")
            {
                camera_factor = 1;
                camera_cx = 311.0;
                camera_cy = 244.0;
                camera_fx = 593.0;
                camera_fy = 588.0;
            }
            else if(Camera_Settings::depth_resolution == "320*240")
            {
                camera_factor = 1;
                camera_cx = 311.0*0.5;
                camera_cy = 244.0*0.5;
                camera_fx = 593.0*0.5;
                camera_fy = 588.0*0.5;
            }

            if(bcq_colorMat.try_dequeue(colorMat))
            {
                cloudRGB->clear(); //���õ���Ϊ��

                //�������ͼ
                for (int i = 0; i < depthMat.rows; ++i)
                {
                    uchar* depthData = depthMat.data + i*depthMat.step;
                    uchar* colorData = colorMat.data + i*colorMat.step;
                    for (int j = 0; j < depthMat.cols; ++j)
                    {
                        if (depthData == 0)
                            continue;

                        pcl::PointXYZRGB point;

                        //�����Ŀռ�����
                        point.z = double(*(depthData++)) / camera_factor;
                        point.x = (j - camera_cx) * point.z / camera_fx;
                        point.y = -(i - camera_cy) * point.z / camera_fy;

                        //�Ӳ�ɫͼ���л�ȡ�õ����ɫ
                        point.b = *(colorData++);
                        point.g = *(colorData++);
                        point.r = *(colorData++);

                        //�Ѹõ���뵽������
                        cloudRGB->points.push_back(point);
                    }
                }
                bcq_cloudRGB.enqueue(cloudRGB);
            }
            else
            {
                cloud->clear(); //���õ���Ϊ��

                //�������ͼ
                for (int i = 0; i < depthMat.rows; ++i)
                {
                    uchar* depthData = depthMat.data + i*depthMat.step;
                    for (int j = 0; j < depthMat.cols; ++j)
                    {
                        if (depthData == 0)
                            continue;

                        pcl::PointXYZ point;

                        //�����Ŀռ�����
                        point.z = double(*(depthData++)) / camera_factor;
                        point.x = (j - camera_cx) * point.z / camera_fx;
                        point.y = -(i - camera_cy) * point.z / camera_fy;

                        //�Ѹõ���뵽������
                        cloud->points.push_back(point);
                    }
                }
                bcq_cloud.enqueue(cloud);
            }
        }
    }
}
