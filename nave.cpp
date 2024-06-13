#include "nave.h"
Nave::Nave(qreal x, qreal y)
{
    rowPixmap = 0;
    colPixmap = 0;
    width = 128;
    height = 139;
    stripe = new QPixmap(":/imagenes/sprite_spaceship.png");
    posX = x;
    posY = y;
}
QRectF Nave::boundingRect() const
{
    return QRectF(0, 0, width, height);
}
void Nave::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                 QWidget* widget)
{
    QPixmap scaled = stripe->scaled(QSize(256, 1664)); /* scaled to 0.5 factor
        (https://stackoverflow.com/questions/17504653/why-qpixmapscaled-does-not-work)*/
        painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
void Nave::setInitialPosition(qreal a, qreal b){
    setPosX(a);
    setPosY(b);
    setPos(getPosX(), getPosY());
}
qreal Nave::getPosX()
{
    return posX;
}
qreal Nave::getPosY()
{
    return posY;
}
void Nave::setPosX(qreal x)
{
    posX = x;
}
void Nave::setPosY(qreal y)
{
    posY = y;
}
Proyectil* Nave::disparar()
{
    return new Proyectil(getPosX()+55, getPosY());
}
void Nave::advance(int phase)
{
    setPos(getPosX(), getPosY());
    Q_UNUSED(phase);
}

