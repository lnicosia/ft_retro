/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractProjectile.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:41:47 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 19:08:11 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractProjectile.hpp"
#include "AbstractEnemy.hpp"
#include "Player.hpp"
#include <ncurses.h>

AbstractProjectile::AbstractProjectile(void)
{
	
}

AbstractProjectile::AbstractProjectile(Vec2 pos, Vec2 dir, Blueprint *blueprint, int damage):
	AbstractForegroundEntity(pos, dir, blueprint), _damage(damage), _exploded(false)
{
	
}

AbstractProjectile::AbstractProjectile(AbstractProjectile const &instance)
{
	*this = instance;
}

AbstractProjectile::~AbstractProjectile(void)
{
	
}

AbstractProjectile &	AbstractProjectile::operator=(AbstractProjectile const &rhs)
{
	(void)rhs;
	return *this;
}

bool AbstractProjectile::shouldBeCleaned(void)
{
	return (this->_exploded || !this->isOnScreen());
}

int	AbstractProjectile::getDamage(void)
{
	return (this->_damage);
}

int		AbstractProjectile::getColor(void) const
{
	return COLOR_RED;	
}

void	AbstractProjectile::onCollide(Player &player)
{
	player.looseLife();
	this->_exploded = true;
}

void	AbstractProjectile::onCollide(AbstractEnemy &enemy, Map &map)
{
	enemy.takeDamage(this->_damage, map);
	this->_exploded = true;
}

/*void	AbstractProjectile::update(Map &map)
{
	
}*/