/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:04:25 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 16:23:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractWeapon.hpp"
#include "Map.hpp"

AbstractWeapon::AbstractWeapon(long fireRate, std::string projectileName):
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
	if (this->_fireRate > 2)
	{ 
		this->processBeShot(enemy, ws, map.getEnemiesProjectiles(), map);
		this->_fireRate = 0; //check with time 
	}
	else
	{
		this->_fireRate++;
	}
}

void	AbstractWeapon::beShot(Player &player, WeaponSlot ws, Map &map)
{
	if (map.getTime() - this->_fireTimer > this->_fireRate)
	{
		//std::cerr << "new projectile from player" << std::endl;
		this->_fireTimer = map.getTime();
		this->processBeShot(player, ws, map.getPlayerProjectiles(), map);
	}
}
