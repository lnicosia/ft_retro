/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:18:27 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:22:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star3.hpp"
#include "Game.hpp"

Star3::Star3(void)
{
	
}

Star3::Star3(Vec2 pos, Vec2 dir, Blueprint *blueprint): BackgroundEntity(pos, dir, blueprint)
{
	
}

Star3::Star3(Star3 const &instance)
{
	*this = instance;
}

Star3::~Star3(void)
{
	
}

Star3 &	Star3::operator=(Star3 const &rhs)
{
	(void)rhs;
	return *this;
}

int	Star3::getColor(void) const
{
	return (COLOR_WHITE);
}