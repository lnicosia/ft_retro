/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RegularMissile.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:37:10 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 18:30:27 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RegularMissile.hpp"
#include <ncurses.h>

RegularMissile::RegularMissile(void)
{
	
}

RegularMissile::RegularMissile(Vec2 pos, Vec2 dir, Blueprint *blueprint): AbstractProjectile(pos, dir, blueprint, 100)
{
	
}

RegularMissile::RegularMissile(RegularMissile const &instance)
{
	*this = instance;
}

RegularMissile::~RegularMissile(void)
{
	
}

RegularMissile &	RegularMissile::operator=(RegularMissile const &rhs)
{
	(void)rhs;
	return *this;
}

int		RegularMissile::getColor() const
{
	return COLOR_CYAN;
}