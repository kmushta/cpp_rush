#ifndef _MODEL_CLASS_HPP
# define _MODEL_CLASS_HPP

# include <iostream>
# include <cmath>
# include "defines.h"
# include <ncurses.h>

class Model
{
private:
	int			_x;
	int			_y;
	std::string	_matrix;
	int			_posX;
	int			_posY;
	
public:
	Model( void );
	Model( int posX, int posY, int x, int y, std::string matrix );
	Model( Model const &copy );
	~Model( void );
	
	Model	&operator=( Model const &elem );

	char		getCharAt(int x, int y) const;
	int			getX( void ) const;
	int			getY( void ) const;
	int			getPosX( void ) const;
	int			getPosY( void ) const;
	std::string getMatrix( void ) const;
	bool		rmIfColision( Model *other );
	void		rmCharAt( int x, int y );
	bool		isAlive( void ) const;
	void		setPosX(int x);
	void		setPosY(int y);
	void		addPosX(int x);
	void		addPosY(int y);
};

#endif
