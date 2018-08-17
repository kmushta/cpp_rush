#include "Bullet.class.hpp"

Bullet::Bullet( void ) {

}
Bullet::Bullet(int x, int y, int vx, int vy) : GameEntity(x, y, 1) {
	this->setVelX(vx);
	this->setVelY(vy);
	this->setType(1);
}
Bullet::Bullet( Bullet const &copy ) {
	*this = copy;
}
Bullet::~Bullet( void ) {}

