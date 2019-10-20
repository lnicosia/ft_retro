/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEntity.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:39:33 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 18:37:50 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractEntity.hpp"
#include <ncurses.h>
#include <math.h>

AbstractEntity::AbstractEntity(): _position(Vec2(0,0)), _direction(Vec2(0,0)), _blueprint(nullptr)
{
	
}

AbstractEntity::AbstractEntity(Vec2 pos, Vec2 dir, Blueprint *blueprint):_position(pos),
	 _direction(dir), _blueprint(blueprint)
{
	
}

AbstractEntity::AbstractEntity(AbstractEntity const &instance): _blueprint(instance._blueprint)
{
	*this = instance;
}

AbstractEntity::~AbstractEntity(void)
{
	
}

// TODO
AbstractEntity &	AbstractEntity::operator=(AbstractEntity const &rhs)
{
	(void)rhs;
	this->_position = rhs._position;
	this->_direction = rhs._direction;
	this->_blueprint = rhs._blueprint;
	return *this;
}

void	AbstractEntity::render(void) const
{
	if (this->isOnScreen())
	{
		attrset(COLOR_PAIR(this->getColor()));
		this->_blueprint->print(this->_position);
		attrset(COLOR_PAIR(0));
	}
}

Blueprint*	AbstractEntity::getBlueprint(void) const
{
	return (this->_blueprint);
}

Vec2	AbstractEntity::getPosition() const
{
	return this->_position;
}

Vec2	AbstractEntity::getDirection() const
{
	return this->_direction;
}

void	AbstractEntity::setPosition(Vec2 pos)
{
	this->_position = pos;
}

void	AbstractEntity::setDirection(Vec2 dir)
{
	this->_direction = dir;
}

void	AbstractEntity::setBlueprint(Blueprint * b)
{
	this->_blueprint = b;
}

bool	AbstractEntity::isOnScreen(void) const
{
	return this->_position.getX() + this->_blueprint->getSizeX() > 0
		&& this->_position.getX() < COLS
		&& this->_position.getY() + this->_blueprint->getSizeY() + 30 > 0 // +30 for initialising in this area 
		&& this->_position.getY() < LINES; 
}

bool	AbstractEntity::isOnScreen(void)
{
	return this->_position.getX() + this->_blueprint->getSizeX() > 0
		&& this->_position.getX() < COLS
		&& this->_position.getY() + this->_blueprint->getSizeY() + 30 > 0 // +30 for initialising in this area 
		&& this->_position.getY() < LINES; 
}

void AbstractEntity::update(Map &map)
{
	(void)map;

	this->_position += this->_direction;
}


bool	AbstractEntity::collide(const AbstractEntity &entity)
{
	Blueprint	*me = this->getBlueprint();
	Blueprint	*it = entity.getBlueprint();
	Vec2		myPos = this->getPosition();
	Vec2		itsPos = entity.getPosition();

	//If bounding boxes do not intersect, no collision is possible
	if ((int)myPos.getX() + (int)me->getSizeX() - 1 < (int)itsPos.getX()
		|| (int)myPos.getY() + (int)me->getSizeY() - 1 < (int)itsPos.getY()
		|| (int)myPos.getX() > (int)itsPos.getX() + (int)it->getSizeX() - 1
		|| (int)myPos.getY() > (int)itsPos.getY() + (int)it->getSizeY() - 1)
	{
		// std::cerr << "Bounding boxes do not intersect" << std::endl;
		return false;
	}
	// std::cerr << "Bounding boxes do intersect" << std::endl;
	int	mapStartX = fmax(myPos.getX(), itsPos.getX());
	int	mapStartY = fmax(myPos.getY(), itsPos.getY());
	int	mapEndX = fmin(myPos.getX() + me->getSizeX() - 1, itsPos.getX() + it->getSizeX() - 1);
	int	mapEndY = fmin(myPos.getY() + me->getSizeY() - 1, itsPos.getY() + it->getSizeY() - 1);
	int	sharedSizeX = mapEndX - mapStartX + 1;
	// int	sharedSizeY = mapEndY - mapStartY + 1;
	int	myStartX, myStartY, itsStartX, itsStartY;
	if (myPos.getX() < itsPos.getX())
	{
		myStartX = itsPos.getX() - myPos.getX();
		itsStartX = 0;
	}
	else
	{
		itsStartX = myPos.getX() - itsPos.getX();
		myStartX = 0;
	}
	if (myPos.getY() < itsPos.getY())
	{
		myStartY = itsPos.getY() - myPos.getY();
		itsStartY = 0;
	}
	else
	{
		itsStartY = myPos.getY() - itsPos.getY();
		myStartY = 0;
	}
	int	y = 0, x;
	int	maxY = mapEndY - mapStartY, maxX = mapEndX - mapStartX;
	std::string	myString, itsString;
	// std::cerr << "Zone commune : de [" << mapStartX << "][" << mapStartY << "]";
	// std::cerr << " à [" << mapEndX << "][" << mapEndY << "]";
	// std::cerr << " (size = [" << sharedSizeX << "][" << sharedSizeY << "])" << std::endl;
	// std::cerr << "My pos = [" << myPos.getX() << "][" << myPos.getY() << "]" << std::endl;
	// std::cerr << "My end = [" << myPos.getX() + me->getSizeX() - 1 << "][" << myPos.getY() + me->getSizeY() - 1 << "]" << std::endl;
	// std::cerr << "Its pos = [" << itsPos.getX() << "][" << itsPos.getY() << "]" << std::endl;
	// std::cerr << "Its end = [" << itsPos.getX() + it->getSizeX() - 1 << "][" << itsPos.getY() + it->getSizeY() - 1 << "]" << std::endl;
	// std::cerr << "My start = [" << myStartX << "][" << myStartY << "]" << std::endl;
	// std::cerr << "My size = [" << me->getSizeX() << "][" << me->getSizeY() << "]" << std::endl;
	// std::cerr << "Its start = [" << itsStartX << "][" << itsStartY << "]" << std::endl;
	// std::cerr << "Its size = [" << it->getSizeX() << "][" << it->getSizeY() << "]" << std::endl;
	// std::cerr << "Starting to check" << std::endl;
	while (y <= maxY)
	{
		// std::cerr << "y = " << y << std::endl;
		// std::cerr << "Attempting to create a string from me of size " << sharedSizeX;
		// std::cerr << " at index [" << myStartX << "][" << y + myStartY << "]" << std::endl;
		myString = me->getImageNoN().substr(myStartX + (y + myStartY) * me->getSizeX(), sharedSizeX);
		// std::cerr << "Attempting to create a string from it of size " << sharedSizeX;
		// std::cerr << " at index [" << itsStartX << "][" << y + itsStartY << "]" << std::endl;
		itsString = it->getImageNoN().substr(itsStartX + (y + itsStartY) * it->getSizeX(), sharedSizeX);
		// std::cerr << "Comparing \"" << myString << "\" and \"" << itsString << "\"" << std::endl;
		x = 0;
		while (x <= maxX)
		{
			//std::cerr << "x = " << x << std::endl;
			if (myString[x] != ' ' && itsString[x] != ' ')
			{
				//std::cerr << std::endl << "Collision at [" << myPos.getX() + myStartX + x;
				//std::cerr <<  "][" << myPos.getY() + myStartY + y << "]" << std::endl;
				return true;
			}
			x++;
		}
		// std::cerr << "Line ok" << std::endl;
		y++;
	}
	// std::cerr << std::endl << "No collision" << std::endl;
	return false;
}

int		AbstractEntity::getColor(void) const
{
	return COLOR_WHITE;
}