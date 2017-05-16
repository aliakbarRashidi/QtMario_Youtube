#ifndef FLOWER_H
#define FLOWER_H
#include <QGraphicsItem>
#include <QPixmap>
#include "objecttype.h"
#include <QTimer>
#include <QObject>
#include <typeinfo>
#include <QGraphicsScene>

class Flower : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum { Type = UserType + flowerType };
    Flower(QRectF platformRect, int direction,QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;

public slots:
    void nextFrame();

signals:
    void marioSizeStatusf(int);

private:

    int mCurrentFrame;
    QPixmap mPixmap;
    QRectF mPlatform;
    int mDirection;
    bool up;
    bool right;
    bool down;
    bool right2;

};
#endif // FLOWER_H
