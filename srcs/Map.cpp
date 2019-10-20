/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:51:29 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 11:41:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Map.hpp"
#include "Alien.hpp"
#include <ncurses.h>

//collision type:

//player - pickups
//player - enemies
//player - enemy Projectiles
//player own lasers - enemies

//-> will need a list of
// pickups, enemies, enemy projectiles, own projectiles

Map::Map(void):  _factory(), _background(), _enemies(),
	_playerProjectiles(), _pickups(), _player(nullptr),
	_enemySpawnRate(0.02), _enemySpawnTimer(0)
{
	this->_player = this->_factory.createPlayerAtMapCreation();
	//this->_enemies.add(new Alien());
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

int		Map::getScore() const
{
	return this->_score;
}

Vec2	Map::_randomPos()
{
	Vec2 res;

	res.setY(-2);
	res.setX(rand() % (COLS - 0 + 1) + 0);
	return res;
}

void	Map::update()
{
 	this->_background.update(*this);
	//Generate new enemy
	//std::cerr << "Time = " << ((double)clock() / CLOCKS_PER_SEC) << std::endl;
	if ((double)clock() / CLOCKS_PER_SEC - this->_enemySpawnTimer > this->_enemySpawnRate)
	{
		this->_enemySpawnTimer = (double)clock() / CLOCKS_PER_SEC;
		this->_enemies.add(this->_factory.createEntity("alien", Map::_randomPos(), Vec2(0, 0.3)));
		this->_enemies.add(this->_factory.createEntity("life", Map::_randomPos(), Vec2(0, 0.3)));
		this->_enemies.add(this->_factory.createEntity("cash", Map::_randomPos(), Vec2(0, 0.3)));
	}
 	this->_enemies.update(*this);
// 	this->_enemiesProjectiles.update(*this);
 	this->_player->update(*this);
// 	this->_playerProjectiles.update(*this);
// 	this->_pickups.update(*this);
}

void	Map::render(void) const
{
	this->_background.render();
	this->_enemies.render();
	this->_enemiesProjectiles.render();
	//std::cerr << "trying to render player" << std::endl;
	this->_player->render();
	//std::cerr << "player rendered" << std::endl;
	this->_playerProjectiles.render();
	this->_pickups.render();
}

void	Map::clean(void)
{
	this->_background.clean();
	this->_enemies.clean();
	this->_enemiesProjectiles.clean();
	this->_playerProjectiles.clean();
	this->_pickups.clean();
}

EntityContainer	&	Map::getBackground(void)
{
	return (this->_background);
}

EntityContainer	&	Map::getEnemies(void)
{
	return (this->_enemies);
}

EntityContainer	&	Map::getPlayerProjectiles(void)
{
	return (this->_playerProjectiles);
}

EntityContainer	&	Map::getEnemiesProjectiles(void)
{
	return (this->_enemiesProjectiles);
}

EntityContainer	&	Map::getPickups(void)
{
	return (this->_pickups);
}