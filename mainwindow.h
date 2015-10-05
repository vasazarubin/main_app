#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKitWidgets/QWebView>
#include <QUrl>
#include <QLineEdit>
#include <QFont>
#include <QPushButton>
#include <QProgressBar>
#include <QtWebKit/QWebSettings>
#include <widgetKeyboard2015/keyboard/widgetKeyBoard.h>
#include <widgetKeyboard2015/keyboard/QKeyPushButton.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QWebView *web_view;
    QUrl* url;
    QLineEdit* insta_search_line;
    QFont* search_font;
    QPushButton* goto_site_btn;
    QProgressBar* load_progress;
    QWidget* kb_widget;
    widgetKeyBoard* keyboard;
    void createEnvironment();
private slots:
    void load();
};

#endif // MAINWINDOW_H
