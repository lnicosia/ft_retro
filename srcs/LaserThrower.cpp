/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LaserThrower.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:17:12 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 10:09:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LaserThrower.hpp"
#include "RegularMissile.hpp"

LaserThrower::LaserThrower(void): AbstractWeapon(0.01, "laser thrower")
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
	AbstractEntity *projectile = new RegularMissile(entity.getPosition() + Vec2(entity.getBlueprint()->getSizeX() / 2, 0) + ws.getOrientation(),
		ws.getOrientation(), new Blueprint("assets/regularMissile.ascii"));
	//map.getEntityFactory().createEntity("laser", entity.getPosition() + ws.getOffset(), ws.getOrientation());
	container.add(projectile);
	(void)entity;
	(void)ws;
	(void)container;
	(void)map;


}