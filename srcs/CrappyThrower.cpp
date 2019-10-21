/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CrappyThrower.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:17:50 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 19:49:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CrappyThrower.hpp"


CrappyThrower::CrappyThrower(void): AbstractWeapon(500, 0.2, "crappy missile")
{
	
}

CrappyThrower::CrappyThrower(CrappyThrower const &instance)
{
	*this = instance;
}

CrappyThrower::~CrappyThrower(void)
{
	
}

CrappyThrower &	CrappyThrower::operator=(CrappyThrower const &rhs)
{
	(void)rhs;
	return *this;
}