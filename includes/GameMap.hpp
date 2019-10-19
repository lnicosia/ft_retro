#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include <ncurses.h>

class   GameMap
{
    public:
        /* Constructor and Destructor */
        GameMap();
        GameMap(GameMap & copy);
        ~GameMap();
        /* Getter */
         WINDOW          *getWindow();
        /* Setter */

        /* Operation Overload */
        GameMap&       operator=(const GameMap & var);

        /* Other */
        void            init_ncurse();
        void            kill_ncurses();

    private:
        /* Var Members*/
        WINDOW          *map;
};
#endif // GAMEMAP_HPP