/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WeaponFactory.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:31:05 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 18:42:52 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WeaponFactory.hpp"
#include "LaserThrower.hpp"

WeaponFactory::WeaponFactory(void)
{

}

WeaponFactory::WeaponFactory(WeaponFactory const &instance)
{
	*this = instance;
}

WeaponFactory::~WeaponFactory(void)
{
	
}

WeaponFactory &	WeaponFactory::operator=(WeaponFactory const &rhs)
{
	(void)rhs;
	return *this;
}

std::string WeaponFactory::_factoryIdentifiers[NB_WEAPONS] =
{
	"laser thrower"
};


AbstractWeapon *	WeaponFactory::_createLaserThrower(void)
{
	return new LaserThrower();
}