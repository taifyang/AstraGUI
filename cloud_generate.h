/**
  *@file cloud_generate.h
  *@brief ��������ͷ�ļ�
  */


#ifndef CLOUD_GENERATE_H
#define CLOUD_GENERATE_H


#include "mainwindow.h"


/**
 * @brief The Cloud_Generate class
 */
class Cloud_Generate : public QThread
{
private:
    /**
     * @brief run ��дQThread��run����
     */
    void run();
};


#endif // CLOUD_GENERATE_H
