#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tracePen(Qt::darkGreen)
    , currentPointCircle(nullptr)
{
    setFixedSize(267,341);

    ui->setupUi(this);
    ui->traceView->setScene(&scene);
    backgroundBrush.setColor(Qt::black);
    backgroundBrush.setStyle(Qt::BrushStyle::SolidPattern);
    tracePen.setWidth(2);
    pointPen.setWidth(1);
    pointPen.setColor(Qt::white);
    scene.setSceneRect(5,5,140,140);
    scene.setBackgroundBrush(backgroundBrush);
    //scene.addLine(10,10,70,70, tracePen);
    currentPointCircle = scene.addEllipse(0, ui->traceView->height()/2, 4,4, pointPen);
    increment = ui->incrementSpin->value();
    messageBox.setText("Movimento fora dos limites");



}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addButtonClicked()
{
    std::cout << "addButtonClicked" << std::endl;

}

void MainWindow::removeButtonClicked()
{
    std::cout << "removeButtonClicked" << std::endl;
}


void MainWindow::prevButtonClicked()
{
    std::cout << "prevButtonClicked" << std::endl;
    if (currentPointCircle->x() - increment < 0)
    {

        messageBox.exec();
    }
    else
    {
        currentPointCircle->setX(currentPointCircle->x() - increment);
    }

}


void MainWindow::nextButtonClicked()
{
    std::cout << "nextButtonClicked" << std::endl;
    if (currentPointCircle->x() + increment > ui->traceView->width())
    {
        std::cout << "width: " << ui->traceView->width() << std::endl;
        messageBox.exec();
    }
    else
    {
        currentPointCircle->setX(currentPointCircle->x() + increment);
        std::cout << "x: " << currentPointCircle->x() << std::endl;
    }
}

void MainWindow::incrementSpinChanged()
{
    std::cout << "incrementSpinChanged"<< std::endl;
    increment = ui->incrementSpin->value();
}

void MainWindow::yOscSpinChanged()
{
    std::cout << "yOscSpinChanged"<< std::endl;

    currentPointCircle->setY(ui->yOscSpin->value());
    std::cout << "currentPointCircle->y(): "<< currentPointCircle->y() << std::endl;

}

float MainWindow::map(float y)
{
    return (y - (-150)) * (150 - 0) / (150 - (-150)) + 0;
}
