/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 08:52:21 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 12:48:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroid.hpp"

Asteroid::Asteroid(void): AbstractEnemy()
{
	
}

Asteroid::Asteroid(Vec2 pos, Vec2 dir, Blueprint *blueprint):
    AbstractEnemy(pos, dir, blueprint, 50, 100, WeaponSlot())
{
    
}

Asteroid::Asteroid(Asteroid const &instance)
{
	*this = instance;
}

Asteroid::~Asteroid(void)
{
	
}

/*Asteroid::Asteroid(** replace parameters **)
{
	
}*/

Asteroid &	Asteroid::operator=(Asteroid const &rhs)
{
	(void)rhs;
    return *this;
}

/*void    Asteroid::update(Map &map)
{
    (void)map;
}*/

/*bool    Asteroid::shouldBeCleaned()
{
    return false;
}*/