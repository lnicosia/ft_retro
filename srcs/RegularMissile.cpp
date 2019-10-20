/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RegularMissile.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:37:10 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 14:29:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RegularMissile.hpp"

RegularMissile::RegularMissile(void)
{
	
}

RegularMissile::RegularMissile(Vec2 pos, Vec2 dir, Blueprint *blueprint): AbstractProjectile(pos, dir, blueprint, 500)
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