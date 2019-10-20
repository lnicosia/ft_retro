/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:04:25 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 14:50:07 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractWeapon.hpp"
#include "Map.hpp"

AbstractWeapon::AbstractWeapon(double fireRate, std::string projectileName):
	_fireRate(fireRate), _fireTimer(0), _projectileName(projectileName)
{
	
}

AbstractWeapon::AbstractWeapon(AbstractWeapon const &instance):
	_fireRate(instance._fireRate), _fireTimer(0), _projectileName(instance._projectileName)
{
	
}

AbstractWeapon::~AbstractWeapon(void)
{
	
}

AbstractWeapon::AbstractWeapon(void):
	_fireRate(0), _projectileName("")
{
	
}

AbstractWeapon &	AbstractWeapon::operator=(AbstractWeapon const &rhs)
{
	(void)rhs;
	return *this;
}

void	AbstractWeapon::beShot(AbstractEnemy &enemy, WeaponSlot ws, Map &map)
{
	int value;
	value = (double)clock() / CLOCKS_PER_SEC - this->_fireTimer;
	if (value > this->_fireRate) //&& value > enemy.getMinFireRate()
	{
		this->_fireTimer = (double)clock() / CLOCKS_PER_SEC;
		this->processBeShot(enemy, ws, map.getEnemiesProjectiles(), map);
	}
}

void	AbstractWeapon::beShot(Player &player, WeaponSlot ws, Map &map)
{
	if ((double)clock() / CLOCKS_PER_SEC - this->_fireTimer > this->_fireRate)
	{
		this->_fireTimer = (double)clock() / CLOCKS_PER_SEC;
		this->processBeShot(player, ws, map.getPlayerProjectiles(), map);
	}
}