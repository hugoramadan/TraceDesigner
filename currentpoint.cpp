#include "currentpoint.h"
#include <iostream>
CurrentPoint::CurrentPoint()
{
    _currentPointCenter.setX(0);
    _currentPointCenter.setY(0);
    _indexPosition = 0;
    _circle = new QGraphicsEllipseItem;
}

CurrentPoint::CurrentPoint(int xCenter, int yCenter, int diameter)
{
    _circle = new QGraphicsEllipseItem;
    _diameter = diameter;
    _circle->setRect(xCenter - (_diameter/2), yCenter - (_diameter/2), _diameter, _diameter);
    _currentPointCenter.setX(xCenter);
    _currentPointCenter.setY(yCenter);
}

CurrentPoint::~CurrentPoint()
{
    std::cout << "current point destructor"<< std::endl;
    delete _circle;
}

void CurrentPoint::drawCircle()
{

    _scene->addItem(_circle);
}

void CurrentPoint::setScene(QGraphicsScene* scene)
{
    _scene = scene;
}

void CurrentPoint::setUp(int xCenter, int yCenter, int diameter)
{
    _diameter = diameter;
    _circle->setRect(xCenter - (_diameter/2), yCenter - (_diameter/2), _diameter, _diameter);
    _currentPointCenter.setX(xCenter);
    _currentPointCenter.setY(yCenter);
}

int CurrentPoint::indexPosition()
{
    return _indexPosition;
}

void CurrentPoint::setIndexPosition(int pos)
{
    _indexPosition = pos;
}

void CurrentPoint::setPen(QPen *pen)
{
    _pen = pen;
    _circle->setPen(*_pen);
}

void CurrentPoint::setX(int x)
{
    _currentPointCenter.setX(x);
    _circle->setX(x - _diameter/2);
}

void CurrentPoint::setY(int y)
{
    _currentPointCenter.setY(y);
    _circle->setY(y - _diameter/2);
}

void CurrentPoint::setPos(int x, int y)
{
    setX(x);
    setY(y);
}

int CurrentPoint::x()
{
    return _currentPointCenter.x();
}

int CurrentPoint::y()
{
    return _currentPointCenter.y();
}

QGraphicsEllipseItem *CurrentPoint::circle()
{
    return _circle;
}
