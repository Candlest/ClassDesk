#include "desktopwindow.h"
#include "ui_desktopwindow.h"

#include "win32mod.h"

DesktopWindow::DesktopWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DesktopWindow)
{
    initWindow();
    initTray();
    initBackground();
}

DesktopWindow::~DesktopWindow()
{
    delete ui;
}

void DesktopWindow::initWindow()
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow|Qt::FramelessWindowHint);

    {
        auto size = QGuiApplication::primaryScreen()->geometry();
        screenH = size.height();
        screenW = size.width();
        this->resize(QSize(screenW, screenH));
    }

    this->move(0,0);
    //this->setWindowState(Qt::WindowMaximized);
    SetParent((HWND)this->winId(),GetWorkerW());
}

void DesktopWindow::initTray(){
    tray = new QSystemTrayIcon(QIcon(":/tray/appicon"),this);
    tray_m = new QMenu("Class Desk",this);
    tray_m->addAction(ui->action_about);
    tray_m->addAction(ui->action_setting);
    tray_m->addAction(ui->action_restart);
    tray_m->addAction(ui->action_quit);
    tray->setContextMenu(tray_m);
    tray->show();
}

void DesktopWindow::on_action_quit_triggered()
{
    qApp->exit();
}

void DesktopWindow::on_action_restart_triggered()
{
    QProcess::startDetached(qApp->applicationFilePath(), QStringList("restart"));
    qApp->exit();
}


