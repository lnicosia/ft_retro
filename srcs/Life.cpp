/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Life.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:06:26 by ldedier `          #+#    #+#             */
/*   Updated: 2019/10/20 10:17:28 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Life.hpp"
#include <ncurses.h>

Life::Life(void)
{
	
}


Life::Life(Vec2 pos, Vec2 dir, Blueprint *blueprint): AbstractPickup(pos, dir, blueprint)
{
	
}

Life::Life(Life const &instance)
{
	*this = instance;
}

Life::~Life(void)
{
	
}

Life &	Life::operator=(Life const &rhs)
{
	(void)rhs;
	return *this;	
}

void Life::onCollide(Player &player)
{
	player.gainLife();
	this->setUsed();
}

int		Life::getColor() const
{
	return COLOR_WHITE;
}