/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:18:27 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:19:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star2.hpp"
#include "Game.hpp"

Star2::Star2(void)
{
	
}

Star2::Star2(Vec2 pos, Vec2 dir, Blueprint *blueprint): BackgroundEntity(pos, dir, blueprint)
{
	
}

Star2::Star2(Star2 const &instance)
{
	*this = instance;
}

Star2::~Star2(void)
{
	
}

Star2 &	Star2::operator=(Star2 const &rhs)
{
	(void)rhs;
	return *this;
}

int	Star2::getColor(void) const
{
	return (COLOR_WHITE);
}