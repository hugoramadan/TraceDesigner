#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPoint>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QMessageBox>
#include <QVector>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QBrush backgroundBrush;
    QPen tracePen;
    QPen pointPen;
    QGraphicsEllipseItem* currentPointCircle;
    QGraphicsLineItem* currentLine;
    QMessageBox messageBox;
    int increment;
    QVector<int> traceYOsc;
    int currentPointPosition;


};

#endif // MAINWINDOW_H
