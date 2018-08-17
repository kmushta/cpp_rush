#ifndef _PLAYER_CLASS_HPP
# define _PLAYER_CLASS_HPP

# include "GameEntity.class.hpp"

class Player : public GameEntity
{
public:
	Player( void );
	Player( Player const &copy );
	~Player( void );
	
	using GameEntity::operator=;
	
};

#endif
