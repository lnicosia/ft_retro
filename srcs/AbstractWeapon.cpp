/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:04:25 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 16:23:20 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractWeapon.hpp"

AbstractWeapon::AbstractWeapon(int fireRate, AbstractProjectile *projectile):
	_fireRate(fireRate), _level(0), _laser(projectile)
{
	
}

AbstractWeapon::AbstractWeapon(AbstractWeapon const &instance):
	_fireRate(instance._fireRate), _level(instance._level), _laser(instance._laser)
{
	
}

AbstractWeapon::~AbstractWeapon(void)
{
	
}

AbstractWeapon::AbstractWeapon(void):
	_fireRate(0), _level(0), _laser(nullptr)
{
	
}

AbstractWeapon &	AbstractWeapon::operator=(AbstractWeapon const &rhs)
{
	(void)rhs;
	return *this;
}

void	AbstractWeapon::beShot(AbstractEnemy &enemy, WeaponSlot ws, Map &map)
{
	if (this->_fireRate > 2)
	{ 
		this->processBeShot(enemy, ws, map);
		this->_fireRate = 0; //check with time 
	}
	else
	{
		this->_fireRate++;
	}
}

void	AbstractWeapon::beShot(Player &player, WeaponSlot ws, Map &map)
{
	if (this->_fireRate > 2)
	{ 
		this->processBeShot(player, ws, map);
		this->_fireRate = 0; //check with time 
	}
	else
	{
		this->_fireRate++;
	}
}

void	AbstractWeapon::processBeShot(Player &player, WeaponSlot ws, Map &map)
{
	(void)player;
	(void)ws;
	(void)map;
}

void	AbstractWeapon::processBeShot(AbstractEnemy &enemy, WeaponSlot ws, Map &map)
{
	(void)enemy;
	(void)ws;
	(void)map;
}