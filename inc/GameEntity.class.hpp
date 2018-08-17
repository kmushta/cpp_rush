#ifndef _GAME_ENTITY_HPP
# define _GAME_ENTITY_HPP

# include "Model.class.hpp"
# include "Ncurses.class.hpp"

class GameEntity
{
private:
	Model	*_model;
	int		_velX;
	int		_velY;
	int		_spd;
	bool	_alive;
	int		_wpPos;
	int		_type;

public:
	GameEntity( void );
	GameEntity(int x, int y, std::string model, int w, int h, int spd);
	GameEntity(int x, int y, int spd);
	GameEntity( GameEntity const &copy );
	virtual ~GameEntity( void );
	
	GameEntity	&operator=(GameEntity const &elem);

	int		getVelX( void );
	int		getVelY( void );
	int		getSpeed( void ) const;
	Model	&getModel( void ) const;
	void	update( unsigned long long int cycle, int color );
	void	setVelX(int x);
	void	setVelY(int y);
	int		getPosX( void ) const;
	int		getPosY( void ) const;
	bool	interact( GameEntity *other );
	bool	isAlive( void );
	void	setAlive( bool live );
	void	setWpPos( int pos );
	int		getWpPos( void );
	void	setType(int type);
	int		getType( void );
	virtual void	brain( unsigned long long int );
};

#endif
