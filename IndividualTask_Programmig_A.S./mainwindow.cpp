#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QRadioButton>
#include <QBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
//  Задать заголовок окна
setWindowTitle("Abdugaffor L. - IVT1 B-22 - QT-GI-15");
pic_ = new QLabel(this);

 resize(500, 600);

// Создайте анимацию для изображения
animation_ = new QPropertyAnimation(pic_, "pos", this);
animation_->setDuration(2000);
animation_->setStartValue(QPoint(0, 0));
animation_->setEndValue(QPoint(200, 200));
animation_->setLoopCount(-1);

// Создание и добавление меню
createMenu();
setCentralWidget(pic_);
}


MainWindow::~MainWindow()
{
}

void MainWindow::createMenu()
{
// Create menu bar
QMenuBar *menubar = menuBar();

// Create “File” menu
file_ = menubar->addMenu("Menu");

// Create menu actions
show_pic_ = new QAction("Show picture", this);
choose_pic_ = new QAction("Choose Animation", this);
animate_ = new QAction("Default Animation", this);
stop_ = new QAction("Stop", this);
quit_ = new QAction("Quit", this);

// Add actions to “File” menu
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

    // Create image
    QImage image(300, 300, QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::white);

    // Draw rectangle
    QPainter painter(&image);
    painter.setBrush(Qt::blue);
    painter.drawRect(50, 50, 200, 100);

    // Draw triangle
    QPolygonF triangle;
    triangle.append(QPointF(150, 150));
    triangle.append(QPointF(100, 250));
    triangle.append(QPointF(200, 250));
    painter.setBrush(Qt::red);
    painter.drawPolygon(triangle);

    // Draw circle
    painter.setBrush(Qt::green);
    painter.drawEllipse(QRectF(100, 100, 100, 100));

    // Draw trapezoid
    QPolygonF trapezoid;
    trapezoid.append(QPointF(100, 200));
    trapezoid.append(QPointF(130, 250));
    trapezoid.append(QPointF(170, 250));
    trapezoid.append(QPointF(200, 200));
    painter.setBrush(Qt::yellow);
    painter.drawPolygon(trapezoid);


    QVBoxLayout *layout = new QVBoxLayout(this); // Create a new QVBoxLayout for the main window
    layout->addWidget(pic_); // Add the QLabel to the layout
    layout->setAlignment(Qt::AlignCenter); // Set the alignment of the layout to center
    setLayout(layout); // Set the layout for the main window

    // Show image
    pic_->setPixmap(QPixmap::fromImage(image));
}



void MainWindow::chooseImage()
{
    // Открыть диалог выбора файла изображения
    //QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (.png .jpg .bmp)”));

    // Если файл выбран, установить его в качестве источника изображения
//    if (!fileName.isEmpty()) {
//        QPixmap image(fileName);
//        pic_->setPixmap(image);

        // Создать диалог для выбора скорости и направления движения
        QDialog *dialog = new QDialog(this);
        QVBoxLayout *layout = new QVBoxLayout(dialog);

        // Добавить поле для ввода скорости
        int speed = QInputDialog::getInt(this, tr("Set Speed"), tr("Speed:"), 1, 1);

        // Добавить радиокнопки для выбора направления движения
        QGroupBox *groupbox = new QGroupBox(tr("Direction"), dialog);
        QRadioButton *radio_up_down = new QRadioButton(tr("Up-Down"), groupbox);
        QRadioButton *radio_left_right = new QRadioButton(tr("Left-Right"), groupbox);
        QHBoxLayout *hlayout = new QHBoxLayout(groupbox);
        hlayout->addWidget(radio_up_down);
        hlayout->addWidget(radio_left_right);
        groupbox->setLayout(hlayout);
        layout->addWidget(groupbox);

        // Добавить кнопку для запуска анимации
        QPushButton *button = new QPushButton(tr("Animate"), dialog);
        layout->addWidget(button);
        connect(button, SIGNAL(clicked()), this, SLOT(animateImage()));

        dialog->exec();

        // Установить параметры анимации
        animation_->stop(); // остановить прошлую анимацию
        pic_->move(QPoint(0, 0));



        if (radio_up_down->isChecked()) {
            // set start point to the top left corner of the window, taking into account the width of the image
            animation_->setStartValue(QPoint(pic_->pos().x(), -pic_->height()));
            // set end point to the bottom edge of the window
            animation_->setEndValue(QPoint(pic_->pos().x(), height()));
        } else if (radio_left_right->isChecked()) {
            // set start point to the left edge of the window
            animation_->setStartValue(QPoint(-pic_->width(), pic_->pos().y()));
            // set end point to the right edge of the window, taking into account the width of the image
            animation_->setEndValue(QPoint(width(), pic_->pos().y()));
        }


        animation_->setDuration(2500 / speed);
        animation_->setEasingCurve(QEasingCurve::Linear);
        animation_->setLoopCount(-1);
        animation_->start();
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

 //Reset position of image
pic_->move(QPoint(0, 0));

// Reset position of image to its start position
//    QPoint pos = animation_->startValue().toPoint();
//    pic_->move(pos);
}


void MainWindow::closeApp()
{
// Close application
qApp->quit();
}

