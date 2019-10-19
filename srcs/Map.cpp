/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:51:29 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 18:54:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Map.hpp"

//collision type:

//player - pickups
//player - enemies
//player - enemy Projectiles
//player own lasers - enemies

//-> will need a list of
// pickups, enemies, enemy projectiles, own projectiles

Map::Map(void):  _factory(), _background(), _enemies(),
	_playerProjectiles(), _pickups(), _player(nullptr)
{
	this->_player = this->_factory.createPlayer();
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
	return (*this->_player);
}

void	Map::update()
{
	this->_background.update(*this);
	this->_enemies.update(*this);
	this->_enemiesProjectiles.update(*this);
	this->_player->update(*this);
	this->_playerProjectiles.update(*this);
	this->_pickups.update(*this);
}

void	Map::render(void) const
{
	// this->_background.render();
	// this->_enemies.render();
	// this->_enemiesProjectiles.render();
	//std::cerr << "trying to render player" << std::endl;
	this->_player->render();
	//std::cerr << "player rendered" << std::endl;
	// this->_playerProjectiles.render();
	// this->_pickups.render();
}

void	Map::clean(void)
{
	this->_background.clean();
	this->_enemies.clean();
	this->_enemiesProjectiles.clean();
	this->_playerProjectiles.clean();
	this->_pickups.clean();
}