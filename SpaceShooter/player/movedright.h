#ifndef MOVEDRIGHT_H
#define MOVEDRIGHT_H
#include "SpaceShooter/player/playerstate.h"

class MovedRight : public PlayerState
{
    Q_OBJECT
public:
    MovedRight(Player* player, QState *parent =nullptr);

public slots:
    virtual void moveLeft();
    virtual void moveRight();
    void move();

protected slots:
    void setSprite() ;
private:
    QTimer* mTimer;

};
#endif // MOVEDRIGHT_H
