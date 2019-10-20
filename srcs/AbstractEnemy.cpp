/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEnemy.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:33:44 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 01:19:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractEnemy.hpp"
#include <ncurses.h>
#include "Player.hpp"
#include "Map.hpp"

AbstractEnemy::AbstractEnemy(void)
{
	
}

AbstractEnemy::AbstractEnemy(Vec2 pos, Vec2 dir, Blueprint *blueprint, int health, int scoreOnDeath, WeaponSlot ws): 
	AbstractForegroundEntity(pos, dir, blueprint), _health(health), _scoreOnDeath(scoreOnDeath), _weaponSlot(ws), _dead(false)
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
	if (this->_weaponSlot.getWeapon())
	{
		this->_weaponSlot.getWeapon()->beShot(*this, this->_weaponSlot, map);
	}
}

// bool	AbstractEnemy::shouldBeCleaned()
// {
// 	if (this->getPosition().getY() > LINES)
// 		return true;
// 	return false;
// }

// void	AbstractEnemy::update(Map &map)
// {
// 	(void)map;
// 	this->setPosition(this->getPosition() + this->getDirection());
// }

void AbstractEnemy::onCollide(Player &player)
{
	(void)player;
}

void AbstractEnemy::onCollide(AbstractEnemy &enemy, Map &map)
{
	(void)enemy;
	(void)map;
}

void	AbstractEnemy::drop(Map &map)
{
	(void)map;
}

bool AbstractEnemy::isDead()
{
	return this->_dead;
}

void			AbstractEnemy::die(Player &player)
{
	this->_dead = true;
	player.incScore(this->_scoreOnDeath);
}
