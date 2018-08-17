#include <string>
#include "Enemy.class.hpp"

Enemy::Enemy() :
    GameEntity()
{
}

Enemy::Enemy(const Enemy& enemy)
{
    *this = enemy;
}

Enemy::~Enemy()
{
}

Enemy::Enemy(int y) : GameEntity(RES_W - 10, y, " ####  ##", 3, 3, 1 << 3) {}

void	Enemy::brain( unsigned long long int cycle ) {
	if ((cycle % this->getSpeed()) || !this->isAlive())
		return ;
	if (this->getPosX() < 10) {
		this->setVelY(0);
		this->setVelX(1);
		return ;
	}
	if (this->getPosX() > RES_W - 10) {
		this->setVelY(0);
		this->setVelX(-1);
		return ;
	}
	if (this->getPosY() > RES_H - 10) {
		this->setVelX(0);
		this->setVelY(-1);
		return ;
	}
	if (this->getPosY() < 10) {
		this->setVelX(0);
		this->setVelY(1);
		return ;
	}
	if (rand() % 10 == 0) {
		this->setVelY(0);
		this->setVelX(rand() % 3 - 1);
	} else if (rand() % 10 == 0) {
		this->setVelX(0);
		this->setVelY(rand() % 3 - 1);
	} else if (rand() % 3 == 0 && this->getPosX() > RES_W * 0.75 ) {
		this->setVelY(0);
		this->setVelX(rand() % 2 - 2);
	}
}
