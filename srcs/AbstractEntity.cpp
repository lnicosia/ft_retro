/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEntity.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:39:33 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 17:23:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractEntity.hpp"

AbstractEntity::AbstractEntity(Vec2 pos, Vec2 dir, Blueprint &blueprint):_position(pos), _direction(dir), _blueprint(blueprint)
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
	
}

Blueprint	AbstractEntity::getBlueprint(void)
{
	return (this->_blueprint);
}

void	AbstractEntity::setPosition(Vec2 pos)
{
	this->_position = pos;
}

void	AbstractEntity::setDirection(Vec2 dir)
{
	this->_direction = dir;
}

//TODO

std::ostream &	operator<<(std::ostream &o, AbstractEntity const &instance)
{
	(void)instance;
	return o;
}