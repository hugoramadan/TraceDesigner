#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tracePen(Qt::darkGreen)
{
    setFixedSize(267,341);

    ui->setupUi(this);
    ui->traceView->setScene(&scene);
    backgroundBrush.setColor(Qt::black);
    backgroundBrush.setStyle(Qt::BrushStyle::SolidPattern);
    tracePen.setWidth(2);
    scene.setSceneRect(5,5,140,140);
    scene.setBackgroundBrush(backgroundBrush);
    scene.addLine(10,10,70,70, tracePen);

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
}


void MainWindow::nextButtonClicked()
{
    std::cout << "nextButtonClicked" << std::endl;
}
