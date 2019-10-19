/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractProjectile.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:56:57 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 21:49:15 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractProjectile.hpp"
#include "AbstractEnemy.hpp"
#include "Player.hpp"

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

void	AbstractProjectile::onCollide(Player &player)
{
	player.looseLife();
	this->_exploded = true;
}

void	AbstractProjectile::onCollide(AbstractEnemy &enemy)
{
	enemy.takeDamage(this->_damage);
	this->_exploded = true;
}