/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:04:25 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 18:02:17 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractWeapon.hpp"
#include "Map.hpp"

AbstractWeapon::AbstractWeapon(int fireRate, AbstractProjectile *projectile):
	_fireRate(fireRate), _projectile(projectile)
{
	
}

AbstractWeapon::AbstractWeapon(AbstractWeapon const &instance):
	_fireRate(instance._fireRate), _projectile(instance._projectile)
{
	
}

AbstractWeapon::~AbstractWeapon(void)
{
	
}

AbstractWeapon::AbstractWeapon(void):
	_fireRate(0), _projectile(nullptr)
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
		this->processBeShot((AbstractEntity&)enemy, ws, map.getEnemiesProjectiles());
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
		this->processBeShot(player, ws, map.getPlayerProjectiles());
		this->_fireRate = 0; //check with time 
	}
	else
	{
		this->_fireRate++;
	}
}
