/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:04:25 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 11:12:14 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractWeapon.hpp"

AbstractWeapon::AbstractWeapon(int fireRate, AbstractProjectile &projectile)
{
	
}

AbstractWeapon::AbstractWeapon(AbstractWeapon const &instance)
{
	
}

AbstractWeapon::~AbstractWeapon(void)
{
	
}

AbstractWeapon::AbstractWeapon(void)
{
	
}

AbstractWeapon &	AbstractWeapon::operator=(AbstractWeapon const &rhs)
{
	
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