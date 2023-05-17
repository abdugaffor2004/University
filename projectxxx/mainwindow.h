
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QLabel>
#include <QTimer>
#include <QRadioButton>
#include <QPropertyAnimation>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createMenu();

private slots:
    void showPicture();
    void chooseImage();
    void animateImage();
    void stopAnimation();
    void closeApp();

private:
    QPropertyAnimation *animation_;
    QLabel *pic_;

    QMenu *file_;
    QAction *show_pic_;
    QAction *choose_pic_;
    QAction *animate_;
    QAction *stop_;
    QAction *quit_;
};



