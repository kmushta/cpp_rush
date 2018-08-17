#ifndef _GAME_STATE_CLASS_HPP
# define _GAME_STATE_CLASS_HPP

# include "defines.h"
# include "Ncurses.class.hpp"
# include "GameEntity.class.hpp"
# include "Bullet.class.hpp"
# include "Player.class.hpp"
# include "Enemy.class.hpp"
# include "Asteroid.class.hpp"
# include "Boss.class.hpp"
# include <cstdlib>

class GameState
{
private:
	GameEntity				*_friendly[ARRAY_SIZE];
	GameEntity				*_enemy[ARRAY_SIZE];
	GameEntity				*_player;
	unsigned long long int	_cycle;
	int						_enemies;
	int						_asteroids;
	int						_boss;
	int						_score;
public:
	GameState( void );
	GameState( GameState const &copy );
	~GameState( void );
	
	GameState	&operator=(GameState const &elem);

	void	createAsteroid(float probab);
	void	createEnemy(float probab);
	bool	handleEvents( void );
	bool	update( void );
	void	step( void );
	void	playerBullet( void );
	void	enemyBullet(GameEntity *enemy);
	int		getScore( void );
};

#endif
