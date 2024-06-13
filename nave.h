#ifndef NAVE_H
#define NAVE_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include "proyectil.h"
class Nave : public QGraphicsItem
{
public:
    Nave(qreal, qreal);
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*,
               QWidget*);
    void setInitialPosition(qreal a, qreal b);
    qreal getPosX();
    qreal getPosY();
    void setPosX(qreal);
    void setPosY(qreal);
    Proyectil* disparar();
    void advance(int);
private:
    qreal posX, posY, rowPixmap, colPixmap, width, height;
    QPixmap* stripe;
    //qreal;
};
#endif // NAVE_H
