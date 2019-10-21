/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityContainer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:19:43 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:33:43 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityContainer.hpp"
#include <ctime>

EntityContainer::EntityContainer(void): _size(0)
{
	
}

EntityContainer::EntityContainer(EntityContainer const &instance)
{
	*this = instance;
}

EntityContainer::~EntityContainer(void)
{
	size_t i;

	i = 0;
	while (i < this->_size)
		delete this->_entities[i++];
}

EntityContainer &	EntityContainer::operator=(EntityContainer const &rhs)
{
	this->_size = rhs._size;
	return *this;
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

void	EntityContainer::render() const
{
	size_t i;
	
	i = 0;
	while (i < this->_size)
	{
		this->_entities[i]->render();
		i++;
	}
}

void	EntityContainer::_shiftContainer(size_t i)
{
	//std::cerr << "Deleting entity " << i << " (" << this->_entities[i] << ")" << std::endl;
	delete this->_entities[i];
	while (i < this->_size && i < MAX_ENTITIES)
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

bool	EntityContainer::collide(AbstractEntity &entity)
{
	size_t i;

	i = 0;
	while (i < this->_size)
	{
		if (this->_entities[i]->collide(entity))
			return (true);
		i++;
	}
	return (false);
}

void	EntityContainer::add(AbstractEntity *entity)
{
	if (this->_size < MAX_ENTITIES)
		this->_entities[this->_size++] = entity;
	else
	{
		delete entity;
	}
}

int	EntityContainer::getSize(void)
{
	return (this->_size);
}

AbstractEntity	*	EntityContainer::getEntity(int i)
{
	return (this->_entities[i]);
}
