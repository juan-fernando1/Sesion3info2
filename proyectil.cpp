#include "proyectil.h"
Proyectil::Proyectil(qreal x, qreal y)
{
    rowPixmap = 0;
    colPixmap = 0;
    width = 24;
    height = 24;
    stripe = new QPixmap(":/imagenes/sprite_bullet.png");
    posX = x;
    posY = y;
}
void Proyectil::advance(int phase)
{
    posY -= 5;
    setPos(getPosX(), getPosY());
    Q_UNUSED(phase);
}
QRectF Proyectil::boundingRect() const
{
    return QRectF(0, 0, width, height);
}
void Proyectil::paint(QPainter* painter, const QStyleOptionGraphicsItem*
                                             option, QWidget* widget)
{
    QPixmap scaled = stripe->scaled(QSize(24, 24));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
void Proyectil::setInitialPosition(qreal a, qreal b){
    setPosX(a);
    setPosY(b);
    setPos(getPosX(), getPosY());
}
qreal Proyectil::getPosX()
{
    return posX;
}
qreal Proyectil::getPosY()
{
    return posY;
}
void Proyectil::setPosX(qreal x)
{
    posX = x;
}
void Proyectil::setPosY(qreal y)
{
    posY = y;
}
