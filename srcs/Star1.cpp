/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:18:27 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:18:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star1.hpp"
#include "Game.hpp"

Star1::Star1(void)
{
	
}

Star1::Star1(Vec2 pos, Vec2 dir, Blueprint *blueprint): BackgroundEntity(pos, dir, blueprint)
{
	
}

Star1::Star1(Star1 const &instance)
{
	*this = instance;
}

Star1::~Star1(void)
{
	
}

Star1 &	Star1::operator=(Star1 const &rhs)
{
	(void)rhs;
	return *this;
}

int	Star1::getColor(void) const
{
	return (COLOR_WHITE);
}