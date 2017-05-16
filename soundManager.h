#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QMediaResource>
#include <QSoundEffect>

namespace Ui {
class SoundManager;
}

class SoundManager : public QWidget
{
    Q_OBJECT

public:
    explicit SoundManager(QWidget *parent = 0);
    ~SoundManager();

private:
    Ui::SoundManager *ui;

    QSoundEffect *mario_jump, *mario_death, *coin, *select, *levelClear, *ghost, *shrink, *powerup, *sprout, *kick, *fireball, *hitWarptube;

    QMediaPlayer *soundPlayer, *level1;


public slots:
    void playSoundEffect(QString);
    void setBGMVolume(int);
    void setSFXVolume(int);
};
#endif // SOUNDMANAGER_H
