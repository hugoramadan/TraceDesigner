#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tracePen(Qt::darkGreen)
    , currentPointCircle(nullptr)
    , traceYOsc(50)
    , currentPointPosition(0)
{
    setFixedSize(267,341);

    ui->setupUi(this);
    ui->traceView->setScene(&scene);
    backgroundBrush.setColor(Qt::black);
    backgroundBrush.setStyle(Qt::BrushStyle::SolidPattern);
    tracePen.setWidth(3);
    pointPen.setWidth(1);
    pointPen.setColor(Qt::white);
    scene.setBackgroundBrush(backgroundBrush);

    messageBox.setText("Movimento fora dos limites");

    increment = ui->incrementSpin->value();
    currentPointCircle = scene.addEllipse(increment, ui->traceView->height()/2, 4,4, pointPen);
    currentLine = scene.addLine(0,
                                ui->traceView->height()/2,
                                increment,
                                currentPointCircle->rect().center().y(),
                                tracePen);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addButtonClicked()
{
    std::cout << "addButtonClicked" << std::endl;
    ui->tracePointsList->addItem(ui->yOscSpin->text());
    traceYOsc.append(ui->yOscSpin->value() * (-1));

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

    currentLine = scene.addLine(currentLine->line().x2(),
                                currentLine->line().y2(),
                                currentLine->line().x2() + increment,
                                currentLine->line().y2(),
                                tracePen);

    currentPointPosition++;
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

    currentPointPosition--;

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

    currentPointCircle->setY((ui->yOscSpin->value())* (-1));
    std::cout << "currentPointCircle->y(): "<< currentPointCircle->y() << std::endl;

    currentLine->setLine(currentLine->line().x1(),
                         currentLine->line().y1(),
                         currentPointCircle->x(),
                         currentPointCircle->y() + ui->traceView->width()/2);

    std::cout << currentLine->line().x1() << " "
              << currentLine->line().y1() << " "
              << currentPointCircle->pos().x() << " "
              << currentPointCircle->pos().y() << std::endl;

}

