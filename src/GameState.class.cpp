#include "GameState.class.hpp"

GameState::GameState( void ) {
	Ncurses::init();
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		this->_friendly[i] = 0;
		this->_enemy[i] = 0;
	}
	this->_player = new Player();
	this->_cycle = 1;
	this->_enemies = 0;
	this->_asteroids = 0;
	this->_boss = 0;
	this->_score = 0;
}
GameState::GameState( GameState const &copy ) {
	*this = copy;
}
GameState::~GameState( void ) {}
	
GameState	&GameState::operator=(GameState const &elem) {
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		this->_friendly[i] = elem._friendly[i];
		this->_enemy[i] = elem._enemy[i];
	}
	this->_player = elem._player;
	this->_cycle = elem._cycle;
	this->_enemies = elem._enemies;
	this->_asteroids = elem._asteroids;
	this->_boss = elem._boss;
	this->_score = elem._score;
	return (*this);
}

bool	GameState::handleEvents( void ) {
	this->_player->setVelX(0);
	this->_player->setVelY(0);
	int	c = getch();
	if (c == 'w')
		this->_player->setVelY(-1);
	else if (c == 's')
		this->_player->setVelY(1);
	else if (c == 'a')
		this->_player->setVelX(-1);
	else if (c == 'd' && !(this->_player->getPosX() > RES_W * 0.8))
		this->_player->setVelX(1);
	else if (c == ' ')
		this->playerBullet();
	else if (c == 27)
		return (true);
	else if (c == 'p') {
		mvprintw(RES_H / 2, RES_W / 2, "GAME PAUSED, press P to continue...");
		nodelay(stdscr, FALSE);
		while (getch() != 'p')
			;
		mvprintw(RES_H / 2, RES_W / 2, "                                   ");
		nodelay(stdscr, TRUE);
	}
	return (false);
}

void	GameState::createAsteroid(float probab)
{
	if (rand() < probab * RAND_MAX)
		for (int i = 0; i < ARRAY_SIZE; ++i)
			if (!this->_enemy[i]) {
				this->_enemy[i] = new Asteroid(rand() % RES_H);
				this->_asteroids += 1;
				break ;
			}
}
void	GameState::createEnemy(float probab)
{
	if (this->getScore() && !(this->getScore() % 100) && !this->_boss) {
		for (int i = 0; i < ARRAY_SIZE; ++i) {
			if (!this->_enemy[i]) {
				this->_enemy[i] = new Boss(rand() % (RES_H - 13));
				this->_boss++;
				this->_enemies++;
				return ;
			}
		}
	}
	if (this->_enemies >= 5)
		return ;
	if (rand() < probab * RAND_MAX)
		for (int i = 0; i < ARRAY_SIZE; ++i)
			if (!this->_enemy[i]) {
				this->_enemy[i] = new Enemy(rand() % (RES_H - 3));
				this->_enemies += 1;
				break ;
			}
}
void	GameState::enemyBullet(GameEntity *enemy)
{
	if (enemy->getType() && enemy->getType() != 3)
		return ;
	for (int i = 0; i < ARRAY_SIZE; ++i)
		if (!this->_enemy[i]) {
			if (!enemy->getType()) {
				if (rand() % 100)
					return ;
				this->_enemy[i] = new Bullet(enemy->getPosX(), enemy->getPosY() + enemy->getWpPos(), -1, 0);
				return ;
			} else {
				if (rand() % 20)
					return ;
				this->_enemy[i] = new Bullet(enemy->getPosX(), enemy->getPosY() + enemy->getWpPos(), -1, 0);
				return ;
			}
		}
}
bool	GameState::update( void ) {
	this->createAsteroid(0.02);
	this->createEnemy(0.005);
	this->_player->update(this->_cycle, 1);
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		if (this->_friendly[i]) {
			if (!this->_friendly[i]->isAlive()) {
				delete this->_friendly[i];
				this->_friendly[i] = 0;
			} else {
				this->_friendly[i]->update(this->_cycle, 2);
				if (this->_friendly[i]->getPosX() >= RES_W - 1 && this->_friendly[i]->getType()) {
					mvprintw(this->_friendly[i]->getPosY(), this->_friendly[i]->getPosX(), " ");
					delete this->_friendly[i];
					this->_friendly[i] = 0;
				}
			}
		}
		if (this->_enemy[i]) {
			if (!this->_enemy[i]->isAlive()) {
				if (!this->_enemy[i]->getType())
					this->_enemies--;
				else if (this->_enemy[i]->getType() == 3) {
					this->_boss--;
					this->_enemies--;
				}
				else if (this->_enemy[i]->getType() == 2)
					this->_asteroids--;
				delete this->_enemy[i];
				this->_enemy[i] = 0;
			} else {
				this->_enemy[i]->brain(this->_cycle);
				this->enemyBullet(_enemy[i]);
				if (this->_enemy[i]->getType() == 1)
					this->_enemy[i]->update(this->_cycle, 3);
				else if (this->_enemy[i]->getType() == 2)
					this->_enemy[i]->update(this->_cycle, 4);
				else
					this->_enemy[i]->update(this->_cycle, 5);
				if (this->_enemy[i]->getPosX() <= 0 && this->_enemy[i]->getType() && this->_enemy[i]->getType() != 3) {
					mvprintw(this->_enemy[i]->getPosY(), this->_enemy[i]->getPosX(), " ");
					if (this->_enemy[i]->getType() == 2)
						this->_asteroids -= 1;
					delete this->_enemy[i];
					this->_enemy[i] = 0;
				}
			}
		}
	}
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		if (this->_enemy[i])
			if (this->_player->interact(this->_enemy[i]))
				system("afplay colide.wav&");
	}
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		for (int j = 0; j < ARRAY_SIZE; ++j) {
			if (this->_friendly[i] && this->_enemy[j] && this->_enemy[j]->getType() != 1)
				if (this->_friendly[i]->interact(this->_enemy[j]))
					if (!this->_enemy[j]->getType() || this->_enemy[j]->getType() == 3)
						this->_score++;
		}
	}
	if (!this->_player->isAlive())
		return (false);
	return (true);
}
void	GameState::step( void ) {
	this->_cycle++;
	mvprintw(RES_H + 2, 10, "Current Score: %4d | Life time: %.2f seconds", this->_score, ((float)this->_cycle / 50));
	if (!(this->_cycle % 500))
		this->_score++;
}
void	GameState::playerBullet( void )
{
	for (int i = 0; i < ARRAY_SIZE; ++i)
		if (!this->_friendly[i]) {
			this->_friendly[i] = new Bullet(this->_player->getPosX(), this->_player->getPosY() + this->_player->getWpPos(), 1, 0);
			system("afplay shot.wav&");
			break ;
		}
}
int		GameState::getScore( void ) {
	return (this->_score);
}
