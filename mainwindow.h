#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include <GraphicsView>
#include <QMainWindow>
#include<QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QVector>
#include "nave.h"
#include "enemigo.h"
#include "explosion.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent*);
public slots:
    void actualizar();
private:
    Ui::MainWindow *ui;
    Nave* nave = nullptr;
    QGraphicsScene* scene = nullptr;
    QTimer* timer = nullptr;
    QVector<Enemigo*> enemigos;
    Explosion* explosion = nullptr;
};
#endif // MAINWINDOW_H

