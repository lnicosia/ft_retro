/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:04:25 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 17:38:00 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractWeapon.hpp"
#include "Map.hpp"

AbstractWeapon::AbstractWeapon(long fireRate, float launchPower, std::string projectileName):
	_fireRate(fireRate), _launchPower(launchPower), _fireTimer(0), _projectileName(projectileName)
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
	double value;
	value = (double)clock() / CLOCKS_PER_SEC - this->_fireTimer;
	if (value > this->_fireTimer && value > enemy.getMinFireRate())
	{
		this->_fireTimer = (double)clock() / CLOCKS_PER_SEC;
		this->processBeShot(enemy, ws, map.getEnemiesProjectiles(), map);
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

void	AbstractWeapon::processBeShot(AbstractEntity &entity, WeaponSlot ws, EntityContainer &container, Map &map)
{
	AbstractEntity *projectile = map.getEntityFactory().createEntity(this->_projectileName, entity.getPosition() + ws.getOffset(), ws.getOrientation() * this->_launchPower);
	container.add(projectile);
}

float	AbstractWeapon::getLaunchPower(void)
{
	return (this->_launchPower);
}