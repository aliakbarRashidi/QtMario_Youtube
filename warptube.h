#ifndef WARPTUBE_H
#define WARPTUBE_H
#include <QObject>
#include "objecttype.h"
#include <QGraphicsItem>
#include <QPixmap>
#include "objecttype.h"
#include <typeinfo>


class WarpTube :  public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum { Type = UserType + warpTubeType };
    WarpTube( QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;
    void handleCollosionWithGoomba();
    void nextFrame();
public slots:


signals:



private:

    int mCurrentFrame3;
    QPixmap mPixmap3;
    QRectF mPlatform;
    int mDirection;

};


#endif // WARPTUBE_H
