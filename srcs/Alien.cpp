/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alien.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:53:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 15:39:18 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Alien.hpp"
#include "CrappyThrower.hpp"

Alien::Alien(void): AbstractEnemy()
{
	
}

Alien::Alien(Vec2 pos, Vec2 dir, Blueprint *blueprint):
    AbstractEnemy(pos, dir, blueprint, 50, 100, WeaponSlot(Vec2(0,0), Vec2(0,1), new CrappyThrower()), 0.01)
{
    std::cerr << "New alien spawned" << std::endl;
}

Alien::Alien(Alien const &instance)
{
	*this = instance;
}

Alien::~Alien(void)
{
	
}

/*Alien::Alien(** replace parameters **)
{
	
}*/

Alien &	Alien::operator=(Alien const &rhs)
{
	(void)rhs;
    return *this;
}

/*void    Alien::update(Map &map)
{
    (void)map;
}*/

/*bool    Alien::shouldBeCleaned()
{
    return false;
}*/

// void    Alien::onCollide(Player &player)
// {
//     (void)player;
// }
// void    Alien::onCollide(AbstractEnemy &enemy)
// {
//     (void)enemy;
// }