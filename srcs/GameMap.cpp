#include "GameMap.hpp"

/* -------------------------- Constructor and Destructor -------------------------- */

GameMap::GameMap()
{
}

GameMap::GameMap(GameMap &copy)
{
}

GameMap::~GameMap()
{
    kill_ncurses();
}
/* -------------------------- Operation Overload -------------------------- */

GameMap&            GameMap::operator=(const GameMap & var)
{
    if(this == &var)
		return (*this);
    return(*this);
}

/* -------------------------- Other -------------------------- */

void                GameMap::init_ncurse()
{
    initscr();              // Initialise la structure WINDOW et autres paramètres
    keypad(stdscr, TRUE);   // keybord input (arrow ) to standar screen (stdscr);
    noecho();               /* Don't echo() while we do getch */
    cbreak();               /* Instant user input, but terminal signal kept */
    curs_set(0);            /* Cursor Visibility : 0: Invisible,  1:Terminal-specific normal mode,  2:Terminal-specific high visibility mode*/
    timeout(0);             /* Sets blocking or non-blocking read behavior for the window. If delay is negative, blocking read is used (which will wait indefinitely for input). */
    refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître

    map = newwin(50, 50, 0, 0);	// new window
	wclear(map);						// clear window
	mvwin(map, 0, 0);					// move window
    //endwin(); 			/* End curses mode		  */

}

void                GameMap::kill_ncurses()
{
    endwin(); 			/* End curses mode		  */
}

WINDOW      *GameMap::getWindow()
{
    return map;
}