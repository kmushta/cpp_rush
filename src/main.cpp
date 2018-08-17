#include "defines.h"
#include "GameEntity.class.hpp"
#include "GameState.class.hpp"
#include "Model.class.hpp"
#include "Ncurses.class.hpp"
#include <ncurses.h>
#include <sys/time.h>
#include <iostream>
#include <unistd.h>
#include <ctime>

long int	getMicrotime( void ) {
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int		main( void )
{
	srand(time(0));
	GameState	*game = new GameState();
	long int	timer = getMicrotime();
	long int	d;
	while (true) {
		if (game->handleEvents())
			break ;
		if (!game->update())
			break ;
		game->step();
		refresh();
		d = 20000 - getMicrotime() + timer;
		if (d > 0)
			usleep(d);
		timer = getMicrotime();
	}
	mvprintw(RES_H / 2, RES_W / 2, "YOU LOOSE WITH SCORE: %d !!! Press ESC to exit!", game->getScore());
	nodelay(stdscr, FALSE);
	while (getch() != 27)
		;
	endwin();
	return (0);
}
