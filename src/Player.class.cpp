#include "Player.class.hpp"

Player::Player( void ) : GameEntity(50, 25, ">  >>>>  ", 3, 3, 1 << 1){

}
Player::Player( Player const &copy ) {
	*this = copy;
}
Player::~Player( void ) {}
