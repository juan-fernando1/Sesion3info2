#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    nave = new Nave(10, 10);
    // naves 11, 2, 3, 4, 7 y 10 del mapa de pixeles
    enemigos.push_back(new Enemigo(0, 0, 1470, 128, 185));
    enemigos.push_back(new Enemigo(0, 0, 270, 128, 100));
    enemigos.push_back(new Enemigo(0, 0, 380, 128, 115));
    enemigos.push_back(new Enemigo(0, 0, 500, 128, 115));
    enemigos.push_back(new Enemigo(0, 0, 900, 128, 115));
    enemigos.push_back(new Enemigo(0, 0, 1280, 128, 185));
    scene->setSceneRect(0, 0, 1200, 700);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width()+5, scene->height()+5);
    this->resize(ui->graphicsView->width()+100,
                 ui->graphicsView->height()+100);
    auto background = QImage(":/imagenes/space.jpeg");
    auto scaledBack = background.scaled(1200, 700);
    ui->graphicsView->setBackgroundBrush(scaledBack);
    scene->addItem(nave);
    nave->setInitialPosition(550, 575);
    int d = 0;
    for(auto e : enemigos)
    {
        scene->addItem(e);
        /* rotacion porque en el mapa de pixeles original las naves miran
        hacia arriba*/
            e->setRotation(180);
        // poniendo las naves enemigas separadas
        e->setInitialPosition(250+d, 200);
        d += 175;
    }
    timer = new QTimer;
    timer->start(20);
    connect(timer, &QTimer::timeout, this, &MainWindow::actualizar);
}
MainWindow::~MainWindow()
{
    delete nave;
    delete scene;
    delete ui;
}
void MainWindow::actualizar()
{
    scene->advance();
    for(auto e : enemigos)
    {
        QList<QGraphicsItem*> colisiones = scene->collidingItems(e);
        if(!colisiones.isEmpty())
        {
            for(auto c : colisiones)
            {
                Proyectil *proyectil = dynamic_cast<Proyectil *>(c);
                if(proyectil)
                {
                    qreal x = e->getPosX();
                    qreal y = e->getPosY();
                    auto exp = new Explosion(x, y);
                    scene->removeItem(e);
                    scene->removeItem(proyectil);
                    enemigos.removeOne(e);
                    scene->addItem(exp);
                    // fix por la rotacion de los enemigos
                    exp->setInitialPosition(x+70, y+50);
                    // fix por la rotacion de los enemigos
                    exp->setRotation(180);
                }
            }
        }
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(nave != nullptr)
    {
        if(event->key() == Qt::Key_A)
        {
            nave->setPosX(nave->getPosX()-20);
        }
        else if(event->key() == Qt::Key_D)
        {
            nave->setPosX(nave->getPosX()+20);
        }
        else if(event->key() == Qt::Key_Space)
        {
            auto proyectil = nave->disparar();
            if(proyectil != nullptr)
            {
                scene->addItem(proyectil);
            }
        }
    }
}
