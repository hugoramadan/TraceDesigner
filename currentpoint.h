#ifndef CURRENTPOINT_H
#define CURRENTPOINT_H

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QPoint>
#include <QPen>

class CurrentPoint
{
public:
    CurrentPoint();
    ~CurrentPoint();
    CurrentPoint(int xCenter, int yCenter, int diameter);
    void drawCircle();
    void setScene(QGraphicsScene* scene);
    void setUp(int xCenter, int yCenter, int diameter);
    int indexPosition();
    void setIndexPosition(int pos);
    void setPen(QPen* pen);
    void setX(int x);
    void setY(int y);
    void setPos(int x, int y);
    int x();
    int y();
    QGraphicsEllipseItem* circle();

private:
    QGraphicsScene* _scene;
    QGraphicsEllipseItem* _circle;
    QPoint _currentPointCenter;
    QPen* _pen;
    int _indexPosition;
    int _diameter;

};

#endif // CURRENTPOINT_H
