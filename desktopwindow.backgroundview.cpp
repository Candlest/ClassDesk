#include "desktopwindow.h"

void DesktopWindow::initBackground(){
//    void (*func[4])(void);
//    func[0] = initPictureMode();
//    func[1] = initSildeMode();
//    func[2] = initHTMLMode();
//    func[3] = initVideoMode();
    /*
     * 理应有4种：单图；幻灯片；网页；视频
     * PictureMode, SildeMode, HTMLMode, VideoMode
     * 0， 1， 2， 3
    */
    QString fileName = QCoreApplication::applicationDirPath() + "/background.ini";
    if(!QFile(fileName).exists()){
        QSettings settings(fileName, QSettings::IniFormat);
        settings.setValue("Desktop/mode", 0);
        settings.sync();
    }
    QSettings settings(fileName, QSettings::IniFormat);
    auto mode = settings.value("Desktop/mode").toUInt();
    switch(mode){
    case 0:{
        qDebug() << "Mode: PictureMode";
        initPictureMode();
        break;
    }
    case 1:{
        qDebug() << "Mode: SildeMode";
        initSildeMode();
        break;
    }
    case 2:{
        qDebug() << "Mode: HTMLMode";
        initHTMLMode();
        break;
    }
    case 3:{
        qDebug() << "Mode: VideoMode";
        initVideoMode();
        break;
    }
    default:{
        qDebug() << "Mode: No Found";
        initPictureMode();
        break;
    }
    }
}

void DesktopWindow::initPictureMode(){
    QString fileName = QCoreApplication::applicationDirPath() + "/background.ini";
    qDebug() << QCoreApplication::applicationDirPath();
    QSettings settings(fileName, QSettings::IniFormat);
    if(!settings.contains("PictureMode/image")){
        settings.setValue("PictureMode/image", "/example.jpg");
        settings.sync();
    }
    QString imgPath = settings.value("PictureMode/image").toString();
    auto pix = QPixmap::fromImage(QImage(QCoreApplication::applicationDirPath() + imgPath));
    double PicW = pix.width();
    double PicH = pix.height();
    qDebug()<<PicW<<PicH;
    QPixmap fitpixmap = pix.scaled(PicW*double(screenH/PicH), screenH, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QLabel *label=new QLabel(this);
    label->setPixmap(fitpixmap);
    label->show();

}

void DesktopWindow::initSildeMode(){
    /*使用QML实现*/
    QQuickView *view = new QQuickView;
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setSource(QUrl(QStringLiteral("qrc:/Quick/SlideMode.qml")));
    auto quickWidget = QWidget::createWindowContainer(view, this);
    auto qmlContext = view->rootContext();
    quickWidget->setGeometry(rect());
    quickWidget->show();
}

void DesktopWindow::initHTMLMode()
{
    view = new QWebEngineView(this);
    view->load(QUrl("https://alteredqualia.com/xg/examples/nebula_artefact.html"));
    view->resize(screenW, screenH);
    view->show();
//    webV = wkeCreateWebWindow(WKE_WINDOW_TYPE_CONTROL, (HWND)this->winId(), 0, 0, this->width(),this->height());
//    wkeShowWindow(webV, TRUE);
//    wkeLoadURL(webV, R"(https://www.baidu.com)");//wkeShowWindow
////        QWebEngineView view;
////        view.load(QUrl("https://www.zhihu.com/"));
////        auto quickWidget = QWidget::createWindowContainer(view, this);
////        quickWidget->setGeometry(rect());
////        quickWidget.show();
//    {
//    /*使用miniblink还是Web Engine?*/
////    QString url = R"(https://www.baidu.com)";
////    auto webView = wkeCreateWebWindow(WKE_WINDOW_TYPE_TRANSPARENT, (HWND)this->winId(), 0, 0, this->width(),this->height());
////    wkeShowWindow(webView, TRUE);
////    wkeLoadURL(webView,R"(https://www.baidu.com)");
//    }
}
void DesktopWindow::initVideoMode()
{
    /*使用QML实现*/
    QQuickView *view = new QQuickView;
    auto qmlContext = view->rootContext();
    qmlContext->setContextProperty("appDir", qApp->applicationDirPath());
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setSource(QUrl(QStringLiteral("qrc:/Quick/VideoMode.qml")));
    auto quickWidget = QWidget::createWindowContainer(view, this);
    quickWidget->setGeometry(rect());
    quickWidget->show();
//    QVideoWidget *videoWidget = new QVideoWidget(this);
//    QMediaPlayer *player = new QMediaPlayer();
//    /*从本地读取*/
//    player->setMedia(QUrl(QCoreApplication::applicationDirPath() + "/video.flv"));
//    qDebug() <<QCoreApplication::applicationDirPath() + "/video.flv";
////    player->setMedia(QMediaContent(QUrl(QCoreApplication::applicationDirPath() + "/video.flv")));
//    player->setVideoOutput(videoWidget);
//    player->play();
//    auto quickWidget = QWidget::createWindowContainer(videoWidget, this);
//    quickWidget->setGeometry(rect());
//    quickWidget->show();
}
