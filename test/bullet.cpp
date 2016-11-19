#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include "test/game.h"
extern Game* game;
Bullet::Bullet(QGraphicsItem* parent):QGraphicsPixmapItem(parent)
{
    sound=new QSound(":/music/test/res/boom.wav");

    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/img/test/res/bullet1.png"));
    QTimer* timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem*> mcollidingItems=collidingItems();
    for(auto obj:mcollidingItems)
    {
        if(typeid(*obj)==typeid(Enemy))
        {
            game->score->increase();
            //if(!sound->isFinished())
            //{
            //    sound->stop();
            //}
            sound->play();
            scene()->removeItem(obj);
            scene()->removeItem(this);


            delete obj;
            delete this;
            return;
        }
    }

    setPos(x(),y()-10);

    if(pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}