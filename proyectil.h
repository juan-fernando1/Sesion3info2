#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
class Proyectil : public QGraphicsItem
{
public:
    Proyectil(qreal, qreal);
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*,
               QWidget*);
    void setInitialPosition(qreal a, qreal b);
    qreal getPosX();
    qreal getPosY();
    void setPosX(qreal);
    void setPosY(qreal);
    void advance(int);
private:
    qreal posX, posY;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height;
};
#endif // PROYECTIL_H
