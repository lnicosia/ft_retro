/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CrappyMissile.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:26:10 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 15:38:45 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CrappyMissile.hpp"

CrappyMissile::CrappyMissile(void)
{
	
}
CrappyMissile::CrappyMissile(Vec2 pos, Vec2 dir, Blueprint *blueprint): AbstractProjectile(pos, dir, blueprint, 10)
{
	
}

CrappyMissile::CrappyMissile(CrappyMissile const &instance)
{
	*this = instance;
}

CrappyMissile::~CrappyMissile(void)
{
	
}

CrappyMissile &	CrappyMissile::operator=(CrappyMissile const &rhs)
{
	(void)rhs;
	return *this;
}