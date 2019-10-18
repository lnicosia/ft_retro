/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blueprint.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:40:33 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/18 18:22:26 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Blueprint.hpp"
#include <sstream>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>

Blueprint::Blueprint(void): _x(0), _y(0), _sizeX(0), _sizeY(0)
{
	
}

Blueprint::Blueprint(std::string f): _x(0), _y(0), _sizeX(0), _sizeY(0)
{
    parseBlueprint(f);
}

Blueprint::Blueprint(Blueprint const &instance)
{
	*this = instance;
}

Blueprint::~Blueprint(void)
{
	
}

std::ostream&   operator<<(std::ostream &o, Blueprint const &instance)
{
    std::cout << instance.getImage();
    return o;
}

Blueprint &	Blueprint::operator=(Blueprint const &rhs)
{
	(void)rhs;
    return *this;
}

std::string Blueprint::getImage() const
{
    return this->_image;
}

int         Blueprint::getX() const
{
    return this->_x;
}

int         Blueprint::getY() const
{
    return this->_y;
}

void        Blueprint::setPos(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

int	Blueprint::parseBlueprint(std::string f)
{
    std::ifstream       stream;
    std::stringstream   buffer;
    std::string         buff;
    int                 fd;

    if (f.find_last_of(".ascii") != f.size() - 1)
    {
        std::cerr << "Invalid  file extension" << std::endl;
        return -1;
    }
    stream.open(f);
    if ((fd = open(f.c_str(), O_NOFOLLOW)) == -1 || close(fd) != 0 || stream.fail())
    {
        std::cerr << "Invalid file" << std::endl;
        return -1;
    }
    std::getline(stream, buff);
    if (buff.compare("This is an ascii file!"))
    {
        std::cerr << "Invalid  file" << std::endl;
        return -1;
    }
    while (std::getline(stream, buff))
    {
        this->_image += buff + '\n';
        this->_sizeY++;
        if (buff.size() > this->_sizeX)
            this->_sizeX = buff.size();
    }
    return 0;
}

void    Blueprint::print() const
{
    std::stringstream   ss(this->_image);
    std::string         line;
    size_t screenX, screenY;
    getmaxyx(stdscr, screenY, screenX);
    mvprintw(0, 0, "Screen size = [%d][%d]", screenX, screenY);
    size_t  i = 0;
    while (i < this->_sizeY)
    {
        std::getline(ss, line);
        if (this->_x + line.size() >= screenX)
            line = line.substr(0, screenX - this->_x);
        if (this->_x < 0)
        {
            line = line.substr(-this->_x);
            mvprintw(this->_y + i, 0, line.c_str());
        }
        else
            mvprintw(this->_y + i, this->_x, line.c_str());
        i++;
    }
}