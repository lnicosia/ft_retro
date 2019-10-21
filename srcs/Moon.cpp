/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:22:21 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 19:38:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Moon.hpp"
#include "Game.hpp"

Moon::Moon(void)
{
	
}

Moon::Moon(Vec2 pos, Vec2 dir, Blueprint *blueprint): BackgroundEntity(pos, dir, blueprint)
{
	
}

Moon::Moon(Moon const &instance)
{
	*this = instance;
}

Moon::~Moon(void)
{
	
}

Moon &	Moon::operator=(Moon const &rhs)
{
	(void)rhs;
	return *this;
}

int	Moon::getColor(void) const
{
	return (YELLOW);
}