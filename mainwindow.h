#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addButtonClicked();
    void removeButtonClicked();
    void prevButtonClicked();
    void nextButtonClicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QBrush backgroundBrush;
    QPen tracePen;


};
#endif // MAINWINDOW_H
