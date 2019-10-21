/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cash.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:18:04 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 19:44:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cash.hpp"
#include <ncurses.h>
#include "Game.hpp"

Cash::Cash(void)
{
	
}

Cash::Cash(Vec2 pos, Vec2 dir, Blueprint *blueprint): AbstractPickup(pos, dir, blueprint)
{	
}

Cash::Cash(Cash const &instance)
{
	*this = instance;
}

Cash::~Cash(void)
{
	
}

Cash &	Cash::operator=(Cash const &rhs)
{
	(void)rhs;
	return *this;
}

void	Cash::onCollide(Player &player)
{
	if (!this->isUsed())
	{
		player.incScore(1000);
		this->setUsed();
	}
}

int		Cash::getColor() const
{
    return GREEN;
}