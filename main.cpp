/**
  *@file main.cpp
  *@brief ������Դ�ļ�
  */


#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Astra *w = new Astra;
    w->show();

    return a.exec();
}
