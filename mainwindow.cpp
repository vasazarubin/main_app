#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createEnvironment();
}

void MainWindow::load()
{

}

void MainWindow::createEnvironment()
{
    web_view = new QWebView(this);
    setWindowTitle("Photoapp");
    //web_view->setStyleSheet("");
    load_progress = new QProgressBar(this);
    load_progress->resize(200, 20);
    load_progress->move(300, 15);
    load_progress->setRange(0, 100);
    QObject::connect(web_view, SIGNAL(loadProgress(int)), load_progress, SLOT(setValue(int)));

    search_font = new QFont("Comic Sans MS", 14);

    insta_search_line = new QLineEdit(this);
    insta_search_line->resize(100, 30);
    insta_search_line->move(10, 10);
    insta_search_line->setStyleSheet("border-width: 2px;border-style:solid;border-color:green;border-radius: 10px;background:yellow; color:green;");
    insta_search_line->setFont(*search_font);

    kb_widget = new QWidget(this);
    kb_widget->setStyleSheet("background:white; border-style: solid; border-color:green; border-width:wpz;border-radius:15px;");
    kb_widget->move(400, 500);
    kb_widget->resize(600, 200);

    keyboard = new widgetKeyBoard(true, this, this);
    keyboard->setKeyButtonSize(QSize(5, 5));
    //keyboard->borderFrame(true);
    keyboard->createKeyboard();
    keyboard->setZoomFacility(true);
    keyboard->setFont(*search_font);
    keyboard->move(400, 500);
    keyboard->resize(600, 200);
    keyboard->focusThis(insta_search_line);


    goto_site_btn = new QPushButton("Go to site page", this);
    goto_site_btn->resize(150, 30);
    goto_site_btn->move(120, 10);
    goto_site_btn->setStyleSheet("border-width: 2px;border-style:solid; border-color: green;border-radius: 10px;background:yellow; color:green;");
    goto_site_btn->setFont(*search_font);
    goto_site_btn->setEnabled(true);
    goto_site_btn->setFlat(true);

    web_view->resize(1300, 400);
    web_view->move(50, 50);


    showFullScreen();
    url = new QUrl("http://www.qt.io/ru/");
    if (url->isValid())
    {
        web_view->load(*url);
        insta_search_line->setText("Valid url");
    }
    else
    {
        insta_search_line->setText("Invalid url");
        return;
    }
    QObject::connect(web_view, SIGNAL(loadFinished(bool)), SLOT(load()));
    //QObject::connect(insta_search_line, SIGNAL(editingFinished()), keyboard, SLOT(hide()));
}

MainWindow::~MainWindow()
{
    if (kb_widget != NULL)
        delete kb_widget;
    if (url != NULL)
        delete url;
    if (NULL != keyboard)
        delete keyboard;
    if (search_font != NULL)
        delete search_font;
    if (web_view != NULL)
    {
        web_view->stop();
        delete web_view;
        QWebSettings::clearMemoryCaches();
    }
}
