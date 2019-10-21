/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:28:45 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:59:18 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.hpp"
#include "BossGun.hpp"
#include "Game.hpp"

Boss::Boss(void)
{
	
}

Boss::Boss(Vec2 pos, Vec2 dir, Blueprint *blueprint) :
	AbstractEnemy(pos, dir, blueprint, 5000, 20000, WeaponSlot(Vec2(8, 5), Vec2(0,1), nullptr), 1)

{
	this->getSlot().setWeapon(new BossGun());
}

Boss::Boss(Boss const &instance)
{
	*this = instance;
}

Boss::~Boss(void)
{
	
}

Boss &	Boss::operator=(Boss const &rhs)
{
	(void)rhs;
	return *this;
}

int	Boss::getColor() const
{
	return (RED);
}

void	Boss::update(Map &map)
{
	AbstractEntity::update(map);
	if (this->isOnScreenShouldPrint())
	{
		this->setDirection(Vec2(0, 0));
		this->shoot(map);
	}
}