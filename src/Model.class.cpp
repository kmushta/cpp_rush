#include "Model.class.hpp"

Model::Model( void ) {
	this->_matrix = "-";
	this->_x = 1;
	this->_y = 1;
	this->_posX = 0;
	this->_posY = 0;
}
Model::Model( int posX, int posY, int x, int y, std::string matrix ) {
	if ((int)matrix.length() == x * y && x > 0 && y > 0) {
		this->_x = x;
		this->_y = y;
		this->_matrix = matrix;
	} else {
		this->_matrix = ".";
		this->_x = 1;
		this->_y = 1;
	}
	this->_posX = posX;
	this->_posY = posY;
}
Model::Model( Model const &copy ) {
	*this = copy;
}
Model::~Model( void ) {}
	
Model	&Model::operator=(Model const &elem) {
	this->_matrix = elem.getMatrix();
	this->_x = elem.getX();
	this->_y = elem.getY();
	return (*this);
}

char	Model::getCharAt(int x, int y) const {
	if (x < 0 || x >= this->_x || y < 0 || y >= this->_y)
		return (' ');
	return (this->_matrix[this->_x * y + x]);
}
int		Model::getX( void ) const {
	return (this->_x);
}
int		Model::getY( void ) const {
	return (this->_y);
}
int		Model::getPosX( void ) const {
	return (this->_posX);
}
int		Model::getPosY( void ) const {
	return (this->_posY);
}
std::string Model::getMatrix( void ) const {
	return (this->_matrix);
}
bool	Model::rmIfColision( Model *other ) {
	int	distX = (int)abs(this->_posX - other->getPosX());
	int	distY = (int)abs(this->_posY - other->getPosY());
	if ( (distX > this->_x && distX > other->getX())
		|| (distY > this->_y && distY > other->getY()) )
		return (false);
	for ( int i = 0; i < this->_y; i++ )
		for ( int j = 0; j < this->_x; j++ )
			if ( (this->_matrix)[i * this->_x + j] != ' ' )
				for ( int k = 0; k < other->getY(); k++ )
					for (int l = 0; l < other->getX(); l++ )
						if ( other->getCharAt(l, k) != ' ' )
							if (this->_posX + j == other->getPosX() + l &&
								this->_posY + i == other->getPosY() + k) {
								this->rmCharAt(j, i);
								other->rmCharAt(l, k);
								mvprintw(this->_posY + i, this->_posX + j, " ");
								return (true);
							}
	return (false);
}
void	Model::rmCharAt(int x, int y) {
	if (x >= 0 && x < this->_x && y >= 0 && y < this->_y)
		this->_matrix[this->_x * y + x] = ' ';
}

bool	Model::isAlive( void ) const {
	for ( int i = 0; i < this->_y; i++ )
		for ( int j = 0; j < this->_x; j++ )
			if ( (this->_matrix)[i * this->_x + j] != ' ' )
				return (true);
	return (false);
}
void	Model::setPosX(int x) {
	if (x >= 0 && x + this->_x <= RES_W)
		this->_posX = x;
}
void	Model::setPosY(int y) {
	if (y >= 0 && y + this->_y <= RES_H)
		this->_posY = y;
}
void	Model::addPosX(int x) {
	this->setPosX(this->_posX + x);
}
void	Model::addPosY(int y) {
	this->setPosY(this->_posY + y);
}
