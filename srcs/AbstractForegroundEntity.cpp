/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractForegroundEntity.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:37:47 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 20:39:52 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractForegroundEntity.hpp"
#include <math.h>

AbstractForegroundEntity::AbstractForegroundEntity(void)
{
	
}

AbstractForegroundEntity::AbstractForegroundEntity(Vec2 pos, Vec2 dir, Blueprint *blueprint): AbstractEntity(pos, dir, blueprint)
{
	
}

AbstractForegroundEntity::AbstractForegroundEntity(AbstractForegroundEntity const &instance)
{
	*this = instance;
}

AbstractForegroundEntity::~AbstractForegroundEntity(void)
{
	
}

AbstractForegroundEntity &	AbstractForegroundEntity::operator=(AbstractForegroundEntity const &rhs)
{
	(void)rhs;
	//TODO
	return *this;
}

bool	AbstractForegroundEntity::collide(const AbstractForegroundEntity &entity)
{
	Blueprint	*me = this->getBlueprint();
	Blueprint	*it = entity.getBlueprint();
	Vec2		myPos = this->getPosition();
	Vec2		itsPos = entity.getPosition();

	//If bounding boxes do not intersect, no collision is possible
	if (myPos.getX() + (int)me->getSizeX() - 1 < itsPos.getX()
		|| myPos.getY() + (int)me->getSizeY() - 1 < itsPos.getY()
		|| myPos.getX() > itsPos.getX() + (int)it->getSizeX() - 1
		|| myPos.getY() > itsPos.getY() + (int)it->getSizeY() - 1)
	{
		std::cerr << "Bounding boxes do not intersect" << std::endl;
		return false;
	}
	std::cerr << "Bounding boxes do intersect" << std::endl;
	int	mapStartX = fmax(myPos.getX(), itsPos.getX());
	int	mapStartY = fmax(myPos.getY(), itsPos.getY());
	int	mapEndX = fmin(myPos.getX() + me->getSizeX() - 1, itsPos.getX() + it->getSizeX() - 1);
	int	mapEndY = fmin(myPos.getY() + me->getSizeY() - 1, itsPos.getY() + it->getSizeY() - 1);
	int	sharedSizeX = mapEndX - mapStartX + 1;
	int	sharedSizeY = mapEndY - mapStartY + 1;
	int	myStartX, myEndX, myStartY, myEndY, itsStartX, itsEndX, itsStartY, itsEndY;
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
	myEndX = myStartX + sharedSizeX;
	myEndY = myStartY + sharedSizeY;
	itsEndX = itsStartX + sharedSizeX;
	itsEndY = itsStartY + sharedSizeY;
	int	y = 0, x;
	int	maxY = mapEndY - mapStartY, maxX = mapEndX - mapStartX;
	std::string	myString, itsString;
	std::cerr << "Zone commune : de [" << mapStartX << "][" << mapStartY << "]";
	std::cerr << " à [" << mapEndX << "][" << mapEndY << "]";
	std::cerr << " (size = [" << sharedSizeX << "][" << sharedSizeY << "])" << std::endl;
	std::cerr << "My pos = [" << myPos.getX() << "][" << myPos.getY() << "]" << std::endl;
	std::cerr << "My end = [" << myPos.getX() + me->getSizeX() - 1 << "][" << myPos.getY() + me->getSizeY() - 1 << "]" << std::endl;
	std::cerr << "Its pos = [" << itsPos.getX() << "][" << itsPos.getY() << "]" << std::endl;
	std::cerr << "Its end = [" << itsPos.getX() + it->getSizeX() - 1 << "][" << itsPos.getY() + it->getSizeY() - 1 << "]" << std::endl;
	std::cerr << "My start = [" << myStartX << "][" << myStartY << "]" << std::endl;
	std::cerr << "My size = [" << me->getSizeX() << "][" << me->getSizeY() << "]" << std::endl;
	std::cerr << "Its start = [" << itsStartX << "][" << itsStartY << "]" << std::endl;
	std::cerr << "Its size = [" << it->getSizeX() << "][" << it->getSizeY() << "]" << std::endl;
	std::cerr << "Starting to check" << std::endl;
	while (y <= maxY)
	{
		//std::cerr << "y = " << y << std::endl;
		/*std::cerr << "Attempting to create a string from me of size " << sharedSizeX;
		std::cerr << " at index [" << myStartX << "][" << y + myStartY << "]" << std::endl;*/
		myString = me->getImageNoN().substr(myStartX + (y + myStartY) * me->getSizeX(), sharedSizeX);
		/*std::cerr << "Attempting to create a string from it of size " << sharedSizeX;
		std::cerr << " at index [" << itsStartX << "][" << y + itsStartY << "]" << std::endl;*/
		itsString = it->getImageNoN().substr(itsStartX + (y + itsStartY) * it->getSizeX(), sharedSizeX);
		std::cerr << "Comparing \"" << myString << "\" and \"" << itsString << "\"" << std::endl;
		x = 0;
		while (x <= maxX)
		{
			//std::cerr << "x = " << x << std::endl;
			if (myString[x] != ' ' && itsString[x] != ' ')
			{
				std::cerr << std::endl << "Collision at [" << myPos.getX() + myStartX + x;
				std::cerr <<  "][" << myPos.getY() + myStartY + y << "]" << std::endl;
				return true;
			}
			x++;
		}
		y++;
	}
	std::cerr << std::endl << "No collision" << std::endl;
	return false;
}