#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
class Enemigo : public QGraphicsItem
{
public:
    Enemigo(qreal, qreal, qreal, qreal, qreal);
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*,
               QWidget*);
    void setInitialPosition(qreal a, qreal b);
    qreal getPosX();
    qreal getPosY();
    void setPosX(qreal);
    void setPosY(qreal);
private:
    qreal posX, posY;
    QPixmap* stripe;
    qreal rowPixmap, colPixmap, width, height;
};
#endif // ENEMIGO_H
