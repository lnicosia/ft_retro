#include "TitleMap.hpp"

TitleMap::TitleMap()
{
}

TitleMap::TitleMap(const TitleMap & copy)
{
    *this = copy;
}

TitleMap & TitleMap::operator=(const TitleMap & var)
{
    if (this == &var)
    {
    }
    return(*this);
}

TitleMap::~TitleMap()
{
}

void    TitleMap::init_title_window()
{
    m_wTitle = newpad(4, 41);
    wclear(m_wTitle);
}

WINDOW      *TitleMap::getWindow()
{
    return m_wTitle;
}

void    TitleMap::title_screen_display()
{
    wclear(m_wTitle);
    wattrset(m_wTitle, COLOR_PAIR(3));
	waddstr(m_wTitle, "FT RETRO");
