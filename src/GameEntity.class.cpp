#include "GameEntity.class.hpp"

GameEntity::GameEntity( void ) {
	this->_velX = 0;
	this->_velY = 0;
	this->_spd = 1;
	this->_alive = true;
	this->_model = new Model();
	this->_wpPos = 0;
	this->_type = 0;
}
GameEntity::GameEntity(int x, int y, std::string model, int w, int h, int spd) {
	this->_velX = 0;
	this->_velY = 0;
	this->_spd = spd;
	this->_alive = true;
	this->_wpPos = h / 2;
	this->_type = 0;
	this->_model = new Model(x, y, w, h, model);
}
GameEntity::GameEntity(int x, int y, int spd) {
	this->_velX = 0;
	this->_velY = 0;
	this->_spd = spd;
	this->_alive = true;
	this->_model = new Model();
	this->_model->setPosX(x);
	this->_model->setPosY(y);
	this->_wpPos = 0;
	this->_type = 0;
}
GameEntity::GameEntity( GameEntity const &copy ) {
	*this = copy;
}
GameEntity::~GameEntity( void ) {
	delete this->_model;
}
	
GameEntity	&GameEntity::operator=(GameEntity const &elem) {
	this->_velX = elem.getPosX();
	this->_velY = elem.getPosY();
	this->_spd = elem.getSpeed();
	*(this->_model) = elem.getModel();
	return (*this);
}

int		GameEntity::getVelX( void ) {
	return (this->_velX);
}
int		GameEntity::getVelY( void ) {
	return (this->_velY);
}
int		GameEntity::getSpeed( void ) const {
	return (this->_spd);
}
Model	&GameEntity::getModel( void ) const {
	return (*(this->_model));
}
void	GameEntity::update( unsigned long long int cycle, int color ) {
	if ((cycle % this->_spd) || !this->_alive)
		return ;
	Ncurses::clear(this->_model);
	if (this->_type) {
		this->_model->addPosX(this->_velX);
		this->_model->addPosY(this->_velY);
	} else {
		this->_model->addPosX(2 * this->_velX);
		this->_model->addPosY(this->_velY);
	}
	Ncurses::draw(color, this->_model);
}
bool	GameEntity::interact( GameEntity *other )
{
	if (this->_model->rmIfColision(&other->getModel())) {
		this->_alive = this->_model->isAlive();
		return (true);
	}
	return (false);
}
void	GameEntity::setVelX(int x) {
	this->_velX = x;
}
void	GameEntity::setVelY(int y) {
	this->_velY = y;
}
int		GameEntity::getPosX( void ) const {
	return (this->_model->getPosX());
}
int		GameEntity::getPosY( void ) const {
	return (this->_model->getPosY());
}
bool	GameEntity::isAlive( void )
{
	this->_alive = this->_model->isAlive();
	return (this->_alive);
}
void	GameEntity::setAlive( bool live ) {
	this->_alive = live;
}
void	GameEntity::setWpPos( int pos ) {
	this->_wpPos = pos;
}
int		GameEntity::getWpPos( void ) {
	return (this->_wpPos);
}
void	GameEntity::setType(int type) {
	this->_type = type;
}
int		GameEntity::getType( void ) {
	return (this->_type);
}
void	GameEntity::brain( unsigned long long int ) {}