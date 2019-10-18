/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:51:29 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 16:04:46 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Map.hpp"

Map::Map(void): _nbBgEntities(0), _nbFgEntities(0), _player()
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
	return o;
}