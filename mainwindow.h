#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPoint>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QMessageBox>
#include <QVector>
#include "currentpoint.h"

#define ZERO_Y_OSC ui->traceView->width()/2

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float map(float y);


public slots:
    void addButtonClicked();
    void removeButtonClicked();
    void prevButtonClicked();
    void nextButtonClicked();
    void incrementSpinChanged();
    void yOscSpinChanged();
    void redrawTrace();
    void printTraceYOsc();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QBrush backgroundBrush;
    QPen tracePen;
    QPen pointPen;
    //QGraphicsEllipseItem* currentPointCircle;
    QGraphicsLineItem* currentLine;
    QMessageBox messageBox;
    int increment;
    QVector<int> traceYOsc;
    int currentYOsc;
    int previousYPos;
    CurrentPoint currentPoint;


};

#endif // MAINWINDOW_H
