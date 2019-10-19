#ifndef TITLEMAP_HPP
#define TITLEMAP_HPP

#include <ncurses.h>

class TitleMap
{
    private:
        WINDOW      *m_wTitle;
    public:
        TitleMap();
        TitleMap(const TitleMap & copy);
        TitleMap & operator=(const TitleMap & var);
        ~TitleMap();

        WINDOW          *getWindow();
        void            init_title_window();
        void            title_screen_display();
};


#endif