/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Life.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:06:26 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 00:58:34 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Life.hpp"

Life::Life(void)
{
	
}

Life::Life(Vec2 pos, Blueprint *blueprint): AbstractPickup(pos, Vec2(0, 1), blueprint)
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

void onCollide(Player &player)
{
	player.gainLife();
}
