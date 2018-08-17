#include "Ncurses.class.hpp"

Ncurses::Ncurses( void ) {}
Ncurses::Ncurses( Ncurses const &copy ) {
	*this = copy;
}
Ncurses::~Ncurses( void ) {}
	
Ncurses	&Ncurses::operator=(Ncurses const &elem) {
	(void)elem;
	return (*this);
}

void	Ncurses::init( void ) {
	initscr();
	curs_set(FALSE);
	noecho();
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	for (int i = 0; i < RES_W; ++i)
		mvprintw(RES_H, i, "%c", '_');
	for (int i = 0; i < RES_H; ++i)
		mvprintw(i, RES_W, "%c", '|');
}
void	Ncurses::clear( Model *model ) {
	for (int i = 0; i < model->getY(); ++i)
		for (int j = 0; j < model->getX(); ++j)
			if (model->getCharAt(j, i) != 32)
				mvprintw(model->getPosY() + i, model->getPosX() + j, " ");
}
void	Ncurses::draw( int type, Model *model ) {
	attron(COLOR_PAIR(type));
	for (int i = 0; i < model->getY(); ++i)
		for (int j = 0; j < model->getX(); ++j)
			if (model->getCharAt(j, i) != ' ')
				mvprintw(model->getPosY() + i, model->getPosX() + j, "%c", model->getCharAt(j, i));
	attroff(COLOR_PAIR(type));
}
