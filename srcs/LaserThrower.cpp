/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LaserThrower.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:17:12 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 19:26:41 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LaserThrower.hpp"

LaserThrower::LaserThrower(void): AbstractWeapon(20, "laser thrower")
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
	AbstractEntity *projectile = map._entityFactory.createEntity("laser", entity.getPosition() + ws.getOffset(), ws.getOrientation());
	container.add(projectile);
}