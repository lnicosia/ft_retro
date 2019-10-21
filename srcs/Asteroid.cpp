/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:41:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 19:16:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroid.hpp"
#include <ncurses.h>
#include "Game.hpp"

Asteroid::Asteroid(void): AbstractEnemy()
{
	
}

Asteroid::Asteroid(Vec2 pos, Vec2 dir, Blueprint *blueprint):
    AbstractEnemy(pos, dir, blueprint, 50, 100, WeaponSlot(), 0)
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

int		Asteroid::getColor() const
{
    return RED;
}
