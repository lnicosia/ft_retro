/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BossGun.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:53:00 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:53:02 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BossGun.hpp"
#include "Map.hpp"

BossGun::BossGun(void) : AbstractWeapon(200, 1, "crappy missile")
{
	
}

BossGun::BossGun(BossGun const &instance)
{
	*this = instance;
}

BossGun::~BossGun(void)
{
	
}

BossGun &	BossGun::operator=(BossGun const &rhs)
{
	(void)rhs;
	return *this;	
}

void	BossGun::processBeShot(AbstractEntity &entity, WeaponSlot &ws, EntityContainer &container, Map &map)
{
	AbstractEntity *projectile = map.getEntityFactory().createEntity("crappy missile", entity.getPosition() + ws.getOffset(), 
		Vec2::randomVect());
	container.add(projectile);
	
	projectile = map.getEntityFactory().createEntity("crappy missile", entity.getPosition() + ws.getOffset(), 
		Vec2::randomVect());
	container.add(projectile);
}