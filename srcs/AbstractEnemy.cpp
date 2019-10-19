/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEnemy.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:33:44 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 21:49:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractEnemy.hpp"

AbstractEnemy::AbstractEnemy(void)
{
	
}

AbstractEnemy::AbstractEnemy(Vec2 pos, Vec2 dir, Blueprint *blueprint, int health, int scoreOnDeath, WeaponSlot ws): 
	AbstractForegroundEntity(pos, dir, blueprint), _health(health), _scoreOnDeath(scoreOnDeath), _weaponSlot(ws)
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

void	AbstractEnemy::takeDamage(int damage)
{
	if (damage >= 0)
		this->_health -= damage;
}

bool AbstractEnemy::shouldBeCleaned(void)
{
	return (this->_health <= 0 || !this->isOnScreen());
}

void	AbstractEnemy::shoot(Map &map)
{
	if (this->_weaponSlot.getWeapon())
	{
		this->_weaponSlot.getWeapon()->beShot(*this, this->_weaponSlot, map);
	}
}