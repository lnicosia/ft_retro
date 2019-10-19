/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractProjectile.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:56:57 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 18:58:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractProjectile.hpp"

AbstractProjectile::AbstractProjectile(void)
{
	
}

AbstractProjectile::AbstractProjectile(Vec2 pos, Vec2 dir, Blueprint *blueprint, int damage):
	AbstractForegroundEntity(pos, dir, blueprint), _damage(damage)
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

int	AbstractProjectile::getDamage(void)
{
	return (this->_damage);
}