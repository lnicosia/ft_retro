/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEnemy.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:33:44 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 17:37:26 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractEnemy.hpp"
#include <ncurses.h>
#include "Player.hpp"
#include "Map.hpp"
#include "Life.hpp"
#include "Cash.hpp"

AbstractEnemy::AbstractEnemy(void)
{
	
}

AbstractEnemy::AbstractEnemy(Vec2 pos, Vec2 dir, Blueprint *blueprint, int health, int scoreOnDeath, WeaponSlot ws, float minFireRate): 
	AbstractForegroundEntity(pos, dir, blueprint), _health(health), _scoreOnDeath(scoreOnDeath), _weaponSlot(ws), _dead(false), _minFireRate(minFireRate)
{
	
}

AbstractEnemy::AbstractEnemy(AbstractEnemy const &instance)
{
	*this = instance;
}

AbstractEnemy::~AbstractEnemy(void)
{
	
}

AbstractEnemy &	AbstractEnemy::operator=(AbstractEnemy const &rhs)
{
	(void) rhs;
	//TODO
	return *this;
}

int	AbstractEnemy::getHealth(void)
{
	return (this->_health);
}


int	AbstractEnemy::getScoreOnDeath(void)
{
	return (this->_scoreOnDeath);
}

void	AbstractEnemy::drop(Map &map)
{
	int val = rand() % 100;
	if (val > 98)
		map.getPickups().add(map.getEntityFactory().createLife(getPosition(), getDirection()));
	else if (val >= 50)
		map.getPickups().add(map.getEntityFactory().createCash(getPosition(), getDirection()));
}

void	AbstractEnemy::takeDamage(int damage, Map &map)
{
	if (damage >= 0)
		this->_health -= damage;
	if (this->_health <= 0)
	{
		this->_dead = true;
		map.getPlayer().incScore(this->_scoreOnDeath);
		this->drop(map);
	}
}

bool AbstractEnemy::shouldBeCleaned(void)
{
	return (this->_dead || !this->isOnScreen());
}

void	AbstractEnemy::shoot(Map &map)
{
	//std::cerr << this << std::endl;
	if (this->_weaponSlot.getWeapon())
	{
		//std::cerr << this->_weaponSlot.getWeapon() << std::endl;
		this->_weaponSlot.getWeapon()->beShot(*this, this->_weaponSlot, map);
	}
}

void	AbstractEnemy::update(Map &map)
{
	AbstractEntity::update(map);
	this->shoot(map);
}

void AbstractEnemy::onCollide(Player &player)
{
	(void)player;
}

void AbstractEnemy::onCollide(AbstractEnemy &enemy, Map &map)
{
	(void)enemy;
	(void)map;
}

void			AbstractEnemy::die(Player &player)
{
	this->_dead = true;
	player.incScore(this->_scoreOnDeath);
}

float	AbstractEnemy::getMinFireRate(void)
{
	return (this->_minFireRate);
}