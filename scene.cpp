#include "scene.h"
#include "mainwindow.h"
#include <QApplication>
#include <ctime>
#include <iostream>
#include <QTimer>
#include <QList>
using namespace std;


Scene::Scene()
{
}

void Scene::init()
{
        start_btn = new Button();
        QPixmap start;
        start.load(":/picture/play.jpg");
        start = start.scaled(80,80);
        start_w =30;
        start_h =30;
        start_btn->setPixmap(start);
        start_btn->setPos(300,400);
        addItem(start_btn);

        exit_btn = new Button();
        QPixmap exit;
        exit.load(":/picture/exit.jpg");
        exit = exit.scaled(80,80);
        exit_w =30;
        exit_h =30;
        exit_btn->setPixmap(exit);
        exit_btn->setPos(450,400);
        addItem(exit_btn);
}
void Scene::type1()
{

        drum = new Drum();
        QPixmap obj;
        obj.load(":/picture/face.jpg");
        obj = obj.scaled(60,60);
        drum->setPixmap(obj);
        drum->setPos(500,200);
        addItem(drum);

}
void Scene::type2()
{

        drum = new Drum();
        QPixmap obj;
        obj.load(":/picture/face2.jpg");
        obj = obj.scaled(60,60);
        drum->setPixmap(obj);
        drum->setPos(400,200);
        addItem(drum);


}
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->scenePos().x()>exit_btn->pos().x()&&event->scenePos().x()<exit_btn->pos().x()+80)
    {
        if(event->scenePos().y()>exit_btn->pos().y()&&event->scenePos().y()<exit_btn->pos().y()+80)
        {
            QApplication::exit();
        }
    }
    if(event->scenePos().x()>start_btn->pos().x()&&event->scenePos().x()<start_btn->pos().x()+80)
    {
        if(event->scenePos().y()>start_btn->pos().y()&&event->scenePos().y()<start_btn->pos().y()+80)
        {
            change();
        }
    }
}

void Scene::create()
{
    if(x=0)
    {
        type1();
    }
    if(x=1)
    {
        type2();
    }
}

void Scene::change()
{
    QImage bg;
    bg.load(":/picture/bg_clear.png");
    bg = bg.scaled(800,600);
    this->setBackgroundBrush(bg);
    removeItem(start_btn);
    removeItem(exit_btn);
    qsrand(NULL);
    x=qrand()%2;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(create()));
    timer->start(1000);
}
