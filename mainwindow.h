/**
  *@file mainwindow.h
  *@brief ������ͷ�ļ�
  */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QVTKWidget.h>
#include <QMessageBox>
#include <QAbstractButton>
#include <QTimer>
#include <QThread>
#include <QString>
#include <QFileDialog>

#include <iostream>
#include <opencv2/opencv.hpp>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <OpenNI.h>
#include <vtkAutoInit.h>
#include <vtkRenderWindow.h>

#include "blockingconcurrentqueue.h"
#include "camera_settings.h"
#include "cloud_generate.h"


VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)


typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;
typedef pcl::PointCloud<pcl::PointXYZRGB> PointCloudRGB;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
using namespace moodycamel;
QT_END_NAMESPACE


/**
 * @brief The Astra class
 */
class Astra : public QMainWindow
{
    Q_OBJECT

public:
    explicit Astra(QWidget *parent = 0);

    ~Astra();

    Ui::MainWindow *ui;

private slots:
    /**
     * @brief save_color_image �����ɫͼ
     */
    void save_color_image();

    /**
     * @brief save_depth_image �������ͼ
     */
    void save_depth_image();

    /**
     * @brief save_point_cloud �������
     */
    void save_point_cloud();

    /**
     * @brief open_color_image �򿪲�ɫͼ
     */
    void open_color_image();

    /**
     * @brief open_depth_image �����ͼ
     */
    void open_depth_image();

    /**
     * @brief open_point_cloud �򿪵���
     */
    void open_point_cloud();


    /**
     * @brief close_all �ر������ļ�
     */
    void close_all();

    /**
     * @brief open_camera �����
     */
    void open_camera();

    /**
     * @brief close_camera �ر����
     */
    void close_camera();

    //void set_camera();

    /**
     * @brief show_color_image ��ʾ��ɫͼ
     */
    void show_color_image();

    /**
     * @brief show_depth_image ��ʾ���ͼ
     */
    void show_depth_image();

    /**
     * @brief show_point_cloud ��ʾ����
     */
    void show_point_cloud();

    /**
     * @brief help_guide ʹ��˵��
     */
    void help_guide();

    /**
     * @brief help_about ����AstraGUI
     */
    void help_about();

private:
    /**
     * @brief camera_settings ������ý�����ָ��
     */
    Camera_Settings *camera_settings;

    /**
     * @brief capture ��ɫ����ͷ
     */
    cv::VideoCapture capture;

    /**
     * @brief device �������ͷ
     */
    openni::Device device;

    /**
     * @brief depthStream �����
     */
    openni::VideoStream depthStream;

    /**
     * @brief depthMode ���ģʽ
     */
    openni::VideoMode depthMode;

    /**
     * @brief viewer pclviewer����
     */
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

    /**
     * @brief timerColor ��ɫͼ����ʾ��ʱ��
     */
    QTimer *timerColor;

    /**
     * @brief timerDepth ���ͼ����ʾ��ʱ��
     */
    QTimer *timerDepth;

    /**
     * @brief timerCloud ������ʾ��ʱ��
     */
    QTimer *timerCloud;

    /**
     * @brief colorMat ��ɫͼ��
     */
    cv::Mat colorMat;

    /**
     * @brief depthMat ���ͼ��
     */
    cv::Mat depthMat;

    /**
     * @brief flag_depth ���ͼ�ɼ���־
     */
    bool flag_depth = false;

    /**
     * @brief flag_cloud �������ɱ�־
     */
    bool flag_cloud =false;
};


#endif // MAINWINDOW_H
