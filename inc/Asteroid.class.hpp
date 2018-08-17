#ifndef _ASTEROID_CLASS_HPP
# define _ASTEROID_CLASS_HPP

# include "GameEntity.class.hpp"

class Asteroid : public GameEntity
{
public:
	Asteroid( void );
	Asteroid(int x);
	Asteroid( Asteroid const &copy );
	~Asteroid( void );
	
	using GameEntity::operator=;
	
};

#endif
