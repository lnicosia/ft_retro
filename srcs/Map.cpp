/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:51:29 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 11:09:34 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Map.hpp"

Map::Map(void): _nbFgEntities(0), _nbBgEntities(0), _player()
{
	int i;

	i = 0;
	while (i < MAX_ENTITIES)
	{
		this->_foregroundEntities[i] = nullptr;
		this->_backgroundEntities[i] = nullptr;
		i++;
	}
}

Map::Map(Map const &instance)
{
	*this = instance;
}

Map::~Map(void)
{
	
}

Map &	Map::operator=(Map const &rhs)
{
	this->_nbBgEntities = rhs._nbBgEntities;
	this->_nbFgEntities = rhs._nbFgEntities;
	this->_player = rhs._player;
	return *this;
}

std::ostream &	operator<<(std::ostream &o, Map const &instance)
{
	(void)instance;
	return o;
}

Player &	Map::getPlayer(void)
{
	return (this->_player);
}

void	Map::process(void)
{
	int i;

	this->_player.process();
	i = 0;
	while (i < this->_nbBgEntities)
	{
		this->_backgroundEntities[i]->process();
		i++;
	}
	i = 0;
	while (i < this->_nbFgEntities)
	{
		this->_foregroundEntities[i]->process();
		i++;
	}
}

void	Map::render(void) const
{
	int i;

	this->_player.render();
	i = 0;
	while (i < this->_nbBgEntities)
	{
		this->_backgroundEntities[i]->render();
		i++;
	}
	i = 0;
	while (i < this->_nbFgEntities)
	{
		this->_foregroundEntities[i]->render();
		i++;
	}
}