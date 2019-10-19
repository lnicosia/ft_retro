#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include <ncurses.h>
#include <iostream>
#include "SpaceShip.hpp"

class   GameMap
{
    public:
        /* Constructor and Destructor */
        GameMap();
        GameMap(unsigned int width, unsigned int height);
        GameMap(GameMap & copy);
        ~GameMap();
        /* Getter */
        unsigned int    getWidth();
        unsigned int    getHeight();

        /* Setter */
        void            setWidth(unsigned int width);
        void            setHeight(unsigned int Height);

        /* Operation Overload */
        GameMap&       operator=(const GameMap & var);

        /* Other */
        void            init_ncurse();
        void            kill_ncurses();

    private:
        /* Var Members*/
        unsigned int    m_width;
        unsigned int    m_height;
        WINDOW          *map;
};
#endif // GAMEMAP_HPP
