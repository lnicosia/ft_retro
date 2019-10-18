/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blueprint.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:40:33 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/18 21:57:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Blueprint.hpp"
#include <sstream>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>

Blueprint::Blueprint(void): _sizeX(0), _sizeY(0)
{
	
}

Blueprint::Blueprint(std::string f): _sizeX(0), _sizeY(0)
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

std::string Blueprint::getImageNoN() const
{
    return this->_imageNoN;
}

size_t      Blueprint::getSizeX() const
{
    return this->_sizeX;
}

size_t      Blueprint::getSizeY() const
{
    return this->_sizeY;
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
        this->_imageNoN += buff;
        this->_sizeY++;
        if (buff.size() > this->_sizeX)
            this->_sizeX = buff.size();
    }
    std::cerr << f << " image is [" << this->_sizeX << "][" << this->_sizeY << "]" << std::endl;
    return 0;
}

void    Blueprint::print(Vec2 pos) const
{
    std::stringstream   ss(this->_image);
    std::string         line;
    size_t screenX, screenY;
    getmaxyx(stdscr, screenY, screenX);
    //mvprintw(0, 0, "Screen size = [%d][%d]", screenX, screenY);
    size_t  i = 0;
    while (i < this->_sizeY)
    {
        std::getline(ss, line);
        if (pos.getX() + line.size() >= screenX)
            line = line.substr(0, screenX - pos.getX());
        if (pos.getX() < 0)
        {
            line = line.substr(-pos.getX());
            mvprintw(pos.getY() + i, 0, line.c_str());
        }
        else
            mvprintw(pos.getY() + i, pos.getX(), line.c_str());
        /*if (pos.getX() + line.size() >= screenX)
            line = this->_image.substr(i * this->_sizeX, i * this->_sizeX + screenX - pos.getX());
        else
            line = this->_image.substr(i * this->_sizeX, i * this->_sizeX + this->_sizeX);
        if (pos.getX() < 0)
        mvprintw(pos.getY() + i, )*/
        i++;
    }
}