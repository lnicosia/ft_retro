/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEntity.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:39:33 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 17:14:10 by ldedier          ###   ########.fr       */
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

AbstractEntity &	AbstractEntity::operator=(AbstractEntity const &rhs)
{
	
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

std::ostream &	operator<<(std::ostream &o, AbstractEntity const &instance)
{
	
}