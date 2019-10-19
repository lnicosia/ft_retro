/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blueprint.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:40:33 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/19 12:49:44 by lnicosia         ###   ########.fr       */
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
    std::string         tmp;
    int                 fd;
    size_t              i = 0;

    // Checks if the extension is ".ascii"
    if (f.find_last_of(".ascii") != f.size() - 1)
    {
        std::cerr << "Invalid  file extension" << std::endl;
        return -1;
    }
    stream.open(f);
    // Prevents from opening symbolic links
    if ((fd = open(f.c_str(), O_NOFOLLOW)) == -1 || close(fd) != 0 || stream.fail())
    {
        std::cerr << "Invalid file" << std::endl;
        return -1;
    }
    std::getline(stream, buff);
    // Checks if the first line is correct
    if (buff.compare("This is an ascii file!"))
    {
        std::cerr << "Invalid  file" << std::endl;
        return -1;
    }
    // Get every line in a tmp string and count sizeX and sizeY of our image
    while (std::getline(stream, buff))
    {
        tmp += buff + '\n';
        this->_sizeY++;
        if (buff.size() > this->_sizeX)
            this->_sizeX = buff.size();
    }
    // Copy every line adding missing spaces:
    //      In _image with '\n'
    //      In _imageNoN without
    std::stringstream   sTmp(tmp);
    while (i < this->_sizeY)
    {
        std::getline(sTmp, buff);
        while (buff.size() < this->_sizeX)
            buff += ' ';
        this->_image += buff + '\n';
        this->_imageNoN += buff;
        i++;
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
    mvprintw(0, 0, "My pos = [%d][%d]", pos.getX(), pos.getY());
    size_t  i = 0;
    size_t  x;
    while (i < this->_sizeY)
    {
        std::getline(ss, line);
        if (pos.getX() + line.size() >= screenX)
            line = line.substr(0, screenX - pos.getX());
        if (pos.getX() < 0)
        {
            line = line.substr(-pos.getX());
            x = 0;
            while (x < line.size())
            {
                if (line.at(x) != ' ')
                    mvaddch(pos.getY() + i, x, line.at(x));
                x++;
            }
            //mvprintw(pos.getY() + i, 0, line.c_str());
        }
        else
        {
            x = 0;
            while (x < line.size())
            {
                if (line.at(x) != ' ')
                    mvaddch(pos.getY() + i, pos.getX() + x, line.at(x));
                x++;
            }
            //mvprintw(pos.getY() + i, pos.getX(), line.c_str());
        }
        i++;
    }
}