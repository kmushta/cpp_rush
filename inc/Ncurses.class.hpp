#ifndef _NCURSES_CLASS_H
# define _NCURSES_CLASS_H

# include <ncurses.h>
# include "defines.h"
# include "Model.class.hpp"

class Ncurses
{
public:
	Ncurses( void );
	Ncurses( Ncurses const &copy );
	~Ncurses( void );
	
	Ncurses	&operator=(Ncurses const &elem);

	static void	init( void );
	static void	clear( Model *model );
	static void	draw( int type, Model *model );
};

#endif
