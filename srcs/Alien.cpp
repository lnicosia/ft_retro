/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alien.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:53:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/19 21:46:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Alien.hpp"

Alien::Alien(void): AbstractEnemy()
{
	
}

Alien::Alien(Vec2 pos, Vec2 dir, Blueprint *blueprint, int health, int scoreOnDeath, WeaponSlot ws):
    AbstractEnemy(pos, dir, blueprint, health, scoreOnDeath, ws)
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

bool    Alien::shouldBeCleaned()
{
    return false;
}

void    Alien::onCollide(Player &player)
{
    (void)player;
}
void    Alien::onCollide(AbstractEnemy &enemy)
{
    (void)enemy;
}