#include "Asteroid.class.hpp"

Asteroid::Asteroid( void ) {

}
Asteroid::Asteroid(int x) : GameEntity(RES_W - 2, x, "*", 1, 1, 1 << 3) {
	this->setVelX(-1);
	this->setVelY(0);
	this->setType(2);
}
Asteroid::Asteroid( Asteroid const &copy ) {
	*this = copy;
}
Asteroid::~Asteroid( void ) {}
