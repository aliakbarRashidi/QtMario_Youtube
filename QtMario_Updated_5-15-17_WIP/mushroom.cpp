#include "mushroom.h"
#include "player.h"
#include "smallmario.h"
#include <QPainter>
#include <QDebug>

Mushroom::Mushroom(QRectF platformRect, int direction,QGraphicsItem *parent): QGraphicsItem(parent),mCurrentFrame(),mPlatform(platformRect), mDirection(direction)

{
    setFlag(ItemClipsToShape);
    mPixmap = QPixmap(":images/m40.png");
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(nextFrame()));
    timer->start(100);
    up= true;
    down = true;
    right = true;
    right2 = false;
//qDebug()<< mDirection;
}

void Mushroom::nextFrame(){
/*
    mCurrentFrame += 71;
    if (mCurrentFrame >= 1129 ) {
        mCurrentFrame = 0;
    }
    */

    if(up) {
        if(this->pos().y() > mPlatform.y()-40) {

            setPos(this->pos().x(), this->pos().y() - (mDirection *5));
        }
    }
    if(right){
        if(this->pos().y() == mPlatform.y() -42) {

            up = false;
            setPos(this->pos().x() + (mDirection *5), this->pos().y());
        }
    }

    if(down) {
        if(this->pos().x() > mPlatform.x() + mPlatform.width()+20) {

            right = false;
            setPos(this->pos().x() , this->pos().y() + (mDirection *25));
        }
    }

    if(this->pos().y() > 619) {

        down =false;
        setPos(this->pos().x() + (mDirection *5), 620);
    }

    //Collision Detection
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //If one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){

            // remove Mario and Goomba from the scene but, they are still on the heap
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //emit increaseTheScore(1);

            emit marioSizeStatus(3);
            // delete colliding_items[i]; //deleting the aliens causes segmentation fault
           // qDebug()<<"mushroom deleted";
            delete this;

            // return (all code below refers to bullet that goes beyond level)
            return;

        }
    }
    //If one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(SmallMario)){

            // remove Mario and Goomba from the scene but, they are still on the heap
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //emit increaseTheScore(1);

            emit marioSizeStatus(2);
            delete colliding_items[i];
            qDebug()<<"small mario deleted and big mario added";
            delete this;

            // return (all code below refers to bullet that goes beyond level)
            return;
        }
    }
}

QRectF Mushroom::boundingRect() const {
    return QRectF(0,0,70,50);

}

void Mushroom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 0,70, 50);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);

}

int Mushroom::type() const {
    return Type;
}
