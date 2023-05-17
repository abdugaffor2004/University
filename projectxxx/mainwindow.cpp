#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set window title
    setWindowTitle("Abdugaffor L. - IVT1 B-22 - QT-GI-15");

    // Create label for image
    pic_ = new QLabel(this);

    // Create animation for image
    animation_ = new QPropertyAnimation(pic_, "pos", this);
    animation_->setDuration(2000);
    animation_->setStartValue(QPoint(0, 0));
    animation_->setEndValue(QPoint(200, 200));
    animation_->setLoopCount(-1);

    // Create and add menu
    createMenu();

    // Set central widget as label for image
    setCentralWidget(pic_);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenu()
{
    // Create menu bar
    QMenuBar *menubar = menuBar();

    // Create "File" menu
    file_ = menubar->addMenu("File");

    // Create menu actions
    show_pic_ = new QAction("Show picture", this);
    choose_pic_ = new QAction("Choose", this);
    animate_ = new QAction("Animate", this);
    stop_ = new QAction("Stop", this);
    quit_ = new QAction("Quit", this);

    // Add actions to "File" menu
    file_->addAction(show_pic_);
    file_->addAction(choose_pic_);
    file_->addSeparator();
    file_->addAction(animate_);
    file_->addAction(stop_);
    file_->addSeparator();
    file_->addAction(quit_);

    // Connect signals and slots
    connect(show_pic_, SIGNAL(triggered()), this, SLOT(showPicture()));
    connect(choose_pic_, SIGNAL(triggered()), this, SLOT(chooseImage()));
    connect(animate_, SIGNAL(triggered()), this, SLOT(animateImage()));
    connect(stop_, SIGNAL(triggered()), this, SLOT(stopAnimation()));
    connect(quit_, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void MainWindow::showPicture()
{
    // Show image
    pic_->setPixmap(QPixmap(""));
}

void MainWindow::chooseImage()
{
    // Open file dialog for image selection
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    // If a file was selected, set it as the image source
    if (!fileName.isEmpty()) {
        QPixmap image(fileName);
        pic_->setPixmap(image);
    }
}


void MainWindow::animateImage()
{
    // Start animation
    animation_->start();
}

void MainWindow::stopAnimation()
{
    // Stop animation
    animation_->stop();

    // Reset position of image
    pic_->move( QPoint(0, 0) );
}


void MainWindow::closeApp()
{
    // Close application
    qApp->quit();
}

