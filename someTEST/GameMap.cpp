#include "GameMap.hpp"

/* -------------------------- Constructor and Destructor -------------------------- */

GameMap::GameMap()
{
    m_width = 15;
    m_height = 40;
}

GameMap::GameMap(unsigned int width, unsigned int height)
{
    m_width = width;
    m_height = height;
}

GameMap::GameMap(GameMap &copy)
{
    m_width = copy.m_width;
    m_height = copy.m_height;
}

GameMap::~GameMap()
{
    kill_ncurses();
}

/* -------------------------- Getter -------------------------- */
unsigned int        GameMap::getHeight()
{
    return (m_height);
}

unsigned int        GameMap::getWidth()
{
    return (m_width);
}

/* -------------------------- Setter -------------------------- */
void                GameMap::setHeight(unsigned int height)
{
    m_height = height;
}

/* -------------------------- Operation Overload -------------------------- */

void                GameMap::setWidth(unsigned int width)
{
    m_width = width;
}

GameMap&            GameMap::operator=(const GameMap & var)
{
    std::cout << "Assignation operator called" << std::endl;
    if(this == &var)
		return (*this);
    m_height = var.m_height;
    m_width = var.m_width;
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

    map = newwin(m_height, m_width, 0, 0);
    box(map, 0, 0);
    refresh();
    //endwin(); 			/* End curses mode		  */

}

void                GameMap::kill_ncurses()
{
    endwin(); 			/* End curses mode		  */
}
