/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:51:29 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 16:51:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Map.hpp"
#include "Alien.hpp"
#include <ncurses.h>
#include <sys/time.h>

//collision type:

//player - pickups
//player - enemies
//player - enemy Projectiles
//player own lasers - enemies

//-> will need a list of
// pickups, enemies, enemy projectiles, own projectiles

Map::Map(void):  _factory(), _background(), _enemies(),
	_playerProjectiles(), _pickups(), _player(nullptr),
	_enemySpawnRate(1000), _enemySpawnTimer(0)
{
	struct timeval startTime;
	gettimeofday(&startTime, NULL);
	this->_startTime = startTime.tv_sec * 1000 + startTime.tv_usec / 1000.0;
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

//Use to debug one enemy at a time
// size_t count = 0;

void	Map::update()
{
	struct timeval currTime;
	gettimeofday(&currTime, NULL);
	this->_time = currTime.tv_sec * 1000 + currTime.tv_usec / 1000.0;
	//std::cerr << "time = " << this->_time << std::endl;
 	this->_background.update(*this);
	//Generate new enemy
	//std::cerr << "Time = " << difftime(time(NULL), this->_time) << std::endl;
	if (this->_time - this->_enemySpawnTimer > this->_enemySpawnRate)
	{
		this->_enemySpawnTimer = this->_time;
		this->_enemies.add(this->_factory.createRandomEnemy(Map::_randomPos(), Vec2(0, 0.08)));
		//this->_enemies.add(this->_factory.createRandomEnemy(Vec2(this->_player->getPosition().getX(), 0), Vec2(0, 0.08)));
		//this->_enemies.add(this->_factory.createEntity("asteroid", Map::_randomPos(), Vec2(0, 0.02)));
	}
	// Use to debug one enemy at a time (uncomment global var count)
	// if (!count)
	// {
	// 	this->_enemies.add(this->_factory.createEntity("asteroid", Vec2(this->_player->getPosition().getX(), 0), Vec2(0, 0.02)));
	// 	count++;
	// }
 	this->_enemies.update(*this);
 	this->_enemiesProjectiles.update(*this);
 	this->_player->update(*this);
 	this->_playerProjectiles.update(*this);
 	this->_pickups.update(*this);
	int	i = 0, j;
	AbstractEnemy *currEnemy;
	AbstractProjectile *currProjectile;
	while (i < this->_playerProjectiles.getSize())
	{
		j = 0;
		currProjectile = (AbstractProjectile *)this->_playerProjectiles.getEntity(i);
		while (j < this->_enemies.getSize())
		{
			currEnemy = (AbstractEnemy *)this->_enemies.getEntity(j);
			if (currProjectile->collide(*currEnemy))
				currProjectile->onCollide(*currEnemy, *this);
			j++;
		}
		i++;
	}
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

EntityFactory	&	Map::getEntityFactory(void)
{
	return (this->_factory);
}

long				Map::getTime() const
{
	return this->_time;
}