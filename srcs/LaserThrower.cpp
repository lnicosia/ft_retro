/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LaserThrower.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:17:12 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 16:52:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LaserThrower.hpp"
#include "RegularMissile.hpp"

LaserThrower::LaserThrower(void): AbstractWeapon(300, "laser thrower")
{
	
}

LaserThrower::LaserThrower(LaserThrower const &instance)
{
	*this = instance;
}

LaserThrower::~LaserThrower(void)
{
	
}

LaserThrower &	LaserThrower::operator=(LaserThrower const &rhs)
{
	(void)rhs;
	return *this;
}

void	LaserThrower::processBeShot(AbstractEntity &entity, WeaponSlot ws, EntityContainer &container, Map &map)
{
	AbstractEntity *projectile = map.getEntityFactory().createEntity("regular missile", entity.getPosition() + ws.getOffset(), ws.getOrientation());
	(void)projectile;
	(void)container;
	container.add(projectile);
}