#ifndef DESKTOPWINDOW_H
#define DESKTOPWINDOW_H

#include <QWidget>
#include <QGuiApplication>
#include <QScreen>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QProcess>
#include <QSettings>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QImage>
#include <QLabel>
#include <QQuickView>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QQmlContext>
#include <QtWebEngineWidgets/QtWebEngineWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class DesktopWindow; }
QT_END_NAMESPACE

class DesktopWindow : public QWidget
{
    Q_OBJECT

public:
    DesktopWindow(QWidget *parent = nullptr);
    ~DesktopWindow();

private slots:
    void on_action_quit_triggered();

    void on_action_restart_triggered();

private:
    Ui::DesktopWindow *ui;
    void initWindow();
    void initTray();
    void initContain();
    QSystemTrayIcon *tray;
    QMenu *tray_m;

private:
    void initBackground();
    /*
     * 理应有4种：单图；幻灯片；网页；视频
     * PictureMode, SildeMode, HTMLMode, VideoMode
    */
    //enum BackgroundMode {PictureMode=0, SildeMode=1, HTMLMode=2, VideoMode=3} mode;
    void initPictureMode(), initSildeMode(), initHTMLMode(), initVideoMode();
    int screenH, screenW;
    QWebEngineView* view;
};
#endif // DESKTOPWINDOW_H
