/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityContainer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:19:43 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 15:09:52 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityContainer.hpp"

EntityContainer::EntityContainer(void): _size(0)
{
	
}

EntityContainer::EntityContainer(EntityContainer const &instance)
{
	*this = instance;
}

EntityContainer::~EntityContainer(void)
{
	//TODO
}

EntityContainer &	EntityContainer::operator=(EntityContainer const &rhs)
{
	this->_size = rhs._size;
	return *this;
}

std::ostream &	operator<<(std::ostream &o, EntityContainer const &instance)
{
	
}

void	EntityContainer::update(Map &map) const
{
	size_t i;

	i = 0;
	while (i < this->_size)
	{
		this->_entities[i]->update(map);
		i++;
	}
}

void	EntityContainer::_shiftContainer(size_t i)
{
	delete this->_entities[i];
	while (i < this->_size)
	{
		this->_entities[i] = this->_entities[i + 1];
		i++;
	}
	this->_size--;

}

void	EntityContainer::clean(void)
{
	size_t i;

	i = 0;
	while (i < this->_size)
	{
		if (this->_entities[i]->shouldBeCleaned())
			this->_shiftContainer(i);
		else
			i++;
	}
}

void	EntityContainer::add(AbstractEntity *entity)
{
	if (this->_size < MAX_ENTITIES)
		this->_entities[this->_size++] = entity;
	else
	{
		//throw Exception();
	}
}
