/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEntity.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:39:33 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 22:10:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractEntity.hpp"

AbstractEntity::AbstractEntity(): _position(Vec2(0,0)), _direction(Vec2(0,0)), _blueprint(nullptr)
{
	
}

AbstractEntity::AbstractEntity(Vec2 pos, Vec2 dir, Blueprint &blueprint):_position(pos), _direction(dir), _blueprint(&blueprint)
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
	return *this;
}

void	AbstractEntity::render(void) const
{
	this->_blueprint->print(this->_position);
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

//TODO

std::ostream &	operator<<(std::ostream &o, AbstractEntity const &instance)
{
	(void)instance;
	return o;
}