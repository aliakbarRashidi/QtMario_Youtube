#ifndef FIREBALL_H
#define FIREBALL_H
#include <QGraphicsItem>
#include <QPixmap>
#include "objecttype.h"
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QMediaPlayer>
class SoundManager;

class FireBall: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum { Type = UserType + fireBallType };
    FireBall(int standingDirection, QGraphicsItem *parent = 0);
    ~FireBall();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;

signals:
    void increaseTheScore(int);
    void playSound(QString);
    void changeFireball(int);
    void playTheSound();
    void playHitWarpSound();

public slots:
    void moveBullet();

private:

    enum State {
        notBouncing = 0,
        bouncing,
    };

    int m_StandingDirection;
    State mState;
    int mCurrentFrame;
    QPixmap mPixmap;
    QPixmap mBouncingPixmap;
    QRectF mPlatform;
    int m_CrouchingDirection;
    bool inPosition;
    QTimer *timer;
    SoundManager *soundManager;


};
#endif // FIREBALL_H
