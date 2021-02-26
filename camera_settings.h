/**
  *@file camera_settings.h
  *@brief �������ͷ�ļ�
  */


#ifndef CAMERA_SETTINGS_H
#define CAMERA_SETTINGS_H

#include <QDialog>
#include <QString>


namespace Ui {
class Camera_Settings;
}


/**
 * @brief The Camera_Settings class
 */
class Camera_Settings : public QDialog
{
    Q_OBJECT

public:
    Camera_Settings(QWidget *parent = 0);

    ~Camera_Settings();

    /**
     * @brief color_index ��ɫ����ͷ���
     */
    static int color_index;

    /**
     * @brief color_resolution ��ɫ����ͷ�ֱ���
     */
    static QString color_resolution;

    /**
     * @brief color_fps ��ɫ����ͷ֡��
     */
    static QString color_fps;

    /**
     * @brief depth_resolution �������ͷ�ֱ���
     */
    static QString depth_resolution;

    /**
     * @brief depth_fps �������ͷ֡��
     */
    static QString depth_fps;

    /**
     * @brief flag_applied �������Ӧ�ñ�־
     */
    static bool flag_applied;

private slots:
    /**
     * @brief on_pushButton_apply_clicked Ӧ���������
     */
    void on_pushButton_apply_clicked();

private:
    Ui::Camera_Settings *ui;
};

#endif // CAMERA_SETTINGS_H
