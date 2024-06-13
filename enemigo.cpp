#include "enemigo.h"
Enemigo::Enemigo(qreal x, qreal y, qreal row, qreal w, qreal h)
{
    rowPixmap = row;
    colPixmap = 0;
    width = w;
    height = h;
    stripe = new QPixmap(":/imagenes/sprite_spaceship.png");
    posX = x;
    posY = y;
}
QRectF Enemigo::boundingRect() const
{
    return QRectF(0, 0, width, height);
}
void Enemigo::paint(QPainter* painter, const QStyleOptionGraphicsItem*
                                           option, QWidget* widget)
{
    QPixmap scaled = stripe->scaled(QSize(256, 1664));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
void Enemigo::setInitialPosition(qreal a, qreal b){
    setPosX(a);
    setPosY(b);
    setPos(getPosX(), getPosY());
}
qreal Enemigo::getPosX()
{
    return posX;
}
qreal Enemigo::getPosY()
{
    return posY;
}
void Enemigo::setPosX(qreal x)
{
    posX = x;
}
void Enemigo::setPosY(qreal y)
{
    posY = y;
}
