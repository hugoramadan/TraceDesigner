#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tracePen(Qt::darkGreen)
    //, currentPoint(0,ZERO_Y_OSC)
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
    traceYOsc.append(0);

    //currentPointCircle = scene.addEllipse(increment, ZERO_Y_OSC, 4,4, pointPen);

    currentPoint.setUp(increment,ZERO_Y_OSC, 4);
    currentPoint.setScene(&scene);
    currentPoint.setPen(&pointPen);


    currentLine = scene.addLine(0,
                                ZERO_Y_OSC,
                                increment,
                                currentPoint.y(),
                                tracePen);
    previousYPos = 0; //ZERO_Y_OSC;
    std::cout << previousYPos;
    currentPoint.drawCircle();

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addButtonClicked()
{
    if (currentPoint.x() + increment > ui->traceView->width())
    {
        std::cout << "width: " << ui->traceView->width() << std::endl;
        messageBox.exec();
    }
    else
    {
        currentPoint.setX(currentPoint.x() + increment);
        std::cout << "x: " << currentPoint.x() << std::endl;
    }

    currentLine = scene.addLine(currentLine->line().x2(),
                                currentLine->line().y2(),
                                currentLine->line().x2() + increment,
                                currentLine->line().y2(),
                                tracePen);
    currentYOsc = previousYPos - currentPoint.y();
    traceYOsc.append(currentYOsc);
    ui->tracePointsList->addItem(QString::number(currentYOsc));
    previousYPos = currentPoint.y();
    printTraceYOsc();
    //ui->yOscSpin->setValue(0);
}


void MainWindow::removeButtonClicked()
{
    std::cout << "removeButtonClicked" << std::endl;
}


void MainWindow::prevButtonClicked()
{
    if (currentPoint.x() - increment < 0)
    {
        messageBox.exec();
    }
    else
    {
        currentPoint.setX(currentPoint.x() - increment);
    }
}


void MainWindow::nextButtonClicked()
{
    if (currentPoint.x() + increment > ui->traceView->width())
    {
        std::cout << "width: " << ui->traceView->width() << std::endl;
        messageBox.exec();
    }
    else
    {
        currentPoint.setX(currentPoint.x() + increment);
        std::cout << "x: " << currentPoint.x() << std::endl;
    }
}


void MainWindow::incrementSpinChanged()
{
    increment = ui->incrementSpin->value();
    redrawTrace();

}


void MainWindow::yOscSpinChanged()
{
    currentYOsc = ui->yOscSpin->value()+currentPoint.y();
    currentPoint.setY(ui->yOscSpin->value() * (-1));
    std::cout << "currentPointCircle->y(): "<< currentPoint.y() << std::endl;

    currentLine->setLine(currentLine->line().x1(),
                         currentLine->line().y1(),
                         currentPoint.x(),
                         currentPoint.y() + ZERO_Y_OSC);

    std::cout << currentLine->line().x1() << " "
              << currentLine->line().y1() << " "
              << currentPoint.x() << " "
              << currentPoint.y() << std::endl;

}

void MainWindow::redrawTrace()
{
    printTraceYOsc();
    int currentYPos = ZERO_Y_OSC;

    for (QGraphicsItem* item : scene.items())
        scene.removeItem(item);
    int x=0;

    for(int y=0; y < traceYOsc.size(); ++y)
    {
        scene.addLine(x, currentYPos, x+increment, currentYPos + traceYOsc[y], tracePen);
        currentYPos += traceYOsc[y];
        x += increment;
    }
    currentPoint.drawCircle();
}


void MainWindow::printTraceYOsc()
{
    std::cout << "traceYOsc: ";
    for (int a=0; a< traceYOsc.size();++a)
        std::cout << traceYOsc[a] << " ";

    std::cout << std::endl;
}
