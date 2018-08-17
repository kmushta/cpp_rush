#ifndef _BULLET_CLASS_HPP
# define _BULLET_CLASS_HPP

# include "GameEntity.class.hpp"

class Bullet : public GameEntity
{
public:
	Bullet( void );
	Bullet(int x, int y, int vx, int vy);
	Bullet( Bullet const &copy );
	~Bullet( void );
	
	using GameEntity::operator=;
	
};

#endif
