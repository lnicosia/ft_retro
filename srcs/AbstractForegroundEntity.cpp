/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractForegroundEntity.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:37:47 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 22:12:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractForegroundEntity.hpp"
#include <math.h>

AbstractForegroundEntity::AbstractForegroundEntity(void)
{
	
}

AbstractForegroundEntity::AbstractForegroundEntity(Vec2 pos, Vec2 dir, Blueprint blueprint): AbstractEntity(pos, dir, blueprint)
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
	if (myPos.getX() + (int)me->getSizeX() < itsPos.getX()
		|| myPos.getY() + (int)me->getSizeY() < itsPos.getY()
		|| myPos.getX() > itsPos.getX() + (int)it->getSizeX()
		|| myPos.getY() > itsPos.getY() + (int)it->getSizeY())
	{
		std::cerr << "Bounding boxes do not intersect" << std::endl;
		std::cerr << "my pos = [" << myPos.getX() << "][" << myPos.getY() << "]" << std::endl;
		std::cerr << "my size = [" << me->getSizeX() << "][" << me->getSizeY() << "]" << std::endl;
		std::cerr << "its pos = [" << itsPos.getX() << "][" << itsPos.getY() << "]" << std::endl;
		std::cerr << "its size = [" << it->getSizeX() << "][" << it->getSizeY() << "]" << std::endl;
		return false;
	}
	std::cerr << "Bounding boxes do intersect" << std::endl;
	int	startX = fmax(myPos.getX(), itsPos.getX());
	int	startY = fmax(myPos.getY(), itsPos.getY());
	int	endX = fmin(me->getSizeX(), it->getSizeX());
	int	endY = fmin(me->getSizeY(), it->getSizeY());
	int	myStartX, myEndX, myStartY, myEndY, itsStartX, itsEndX, itsStartY, itsEndY;
	if (myPos.getX() <= itsPos.getX())
	{
		myStartX = itsPos.getX() - myPos.getX();
		myEndX = me->getSizeX();
		itsStartX = 0;
		itsEndX = myPos.getX() + me->getSizeX() - itsPos.getX();
	}
	else
	{
		itsStartX = myPos.getX() - itsPos.getX();
		itsEndX = it->getSizeX();
		myStartX = 0;
		myEndX = itsPos.getX() + it->getSizeX() - myPos.getX();
	}
	if (myPos.getY() <= itsPos.getY())
	{
		myStartY = itsPos.getY() - myPos.getY();
		myEndY = me->getSizeY();
		itsStartY = 0;
		itsEndY = myPos.getY() + me->getSizeY() - itsPos.getY();
	}
	else
	{
		itsStartY = myPos.getY() - itsPos.getY();
		itsEndY = it->getSizeY();
		myStartY = 0;
		myEndY = itsPos.getY() + it->getSizeY() - myPos.getY();
	}
	int	y = 0, x;
	std::string	myString, itsString;
	while (y <= endY - startY)
	{
		myString = me->getImageNoN().substr(myStartX + (y + myStartY) * me->getSizeX(), myEndX + (y + myStartY) * me->getSizeX());
		itsString = it->getImageNoN().substr(itsStartX + (y + myStartY) * it->getSizeX(), itsEndX + (y + myStartY) * it->getSizeX());
		x = 0;
		while (x <= endX - startX)
		{
			if (myString[myStartX + x] != ' ' && itsString[itsStartX + x] != ' ')
			{
				std::cerr << std::endl << "Collision!" << std::endl;
				return true;
			}
			x++;
		}
		y++;
	}
	return false;
}