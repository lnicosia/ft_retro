/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEnemy.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:33:44 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 21:43:38 by lnicosia         ###   ########.fr       */
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

void	AbstractEnemy::shoot(Map &map)
{
	if (this->_weaponSlot.getWeapon())
	{
		this->_weaponSlot.getWeapon()->beShot(*this, this->_weaponSlot, map);
	}
}

void	AbstractEnemy::update(Map &map)
{
	(void)map;
	std::cerr << "Updating position" << std::endl;
	this->setPosition(this->getPosition() + this->getDirection());
}