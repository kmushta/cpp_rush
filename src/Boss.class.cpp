#include <string>
#include "Boss.class.hpp"

Boss::Boss() :
    GameEntity()
{
}

Boss::Boss(const Boss& Boss)
{
    *this = Boss;
}

Boss::~Boss()
{
}

Boss::Boss(int y) : GameEntity(RES_W - 68, y, "\
                                      +--------------+             \
                                      |--------------|             \
                               +---------------------------+       \
                               |---------------------------|       \
                   +---------------------------------------|       \
               +--------------------------------------------------+\
               |--------------------------------------------------|\
+-----------------------------------T-H-E--B-O-S-S----------------|\
             |----------------------------------------------------|\
             +----------------------------------------------------|\
               +--------------------------------------------------+\
                                     |---------------+             \
                                     +----------+                  ", 67, 13, 1 << 2) {
	this->setType(3);
}

void	Boss::brain( unsigned long long int cycle ) {
	if ((cycle % this->getSpeed()) || !this->isAlive())
		return ;
	if (this->getPosX() < RES_W * 0.2) {
		this->setVelY(0);
		this->setVelX(1);
		return ;
	}
	if (this->getPosX() > RES_W - 68) {
		this->setVelY(0);
		this->setVelX(-1);
		return ;
	}
	if (this->getPosY() > RES_H - 13) {
		this->setVelX(0);
		this->setVelY(-1);
		return ;
	}
	if (this->getPosY() < 0) {
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
