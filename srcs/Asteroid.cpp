/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 08:52:21 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 14:35:33 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroid.hpp"

Asteroid::Asteroid(void): AbstractEnemy()
{
	
}

Asteroid::Asteroid(Vec2 pos, Vec2 dir, Blueprint *blueprint):
    AbstractEnemy(pos, dir, blueprint, 50, 100, WeaponSlot(), 0)
{
    std::cerr << "New Asteroid spawned" << std::endl;
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