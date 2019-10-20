/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WeaponSlot.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:48:27 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 09:53:39 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WeaponSlot.hpp"

WeaponSlot::WeaponSlot(void): _offset(Vec2(0, 0)), _orientation(Vec2(0, 0)), _weapon(nullptr)
{
	
}

WeaponSlot::WeaponSlot(Vec2 offset, Vec2 orientation): _offset(offset), _orientation(orientation), _weapon(nullptr)
{

}

WeaponSlot::WeaponSlot(Vec2 offset, Vec2 orientation, AbstractWeapon *weapon): _offset(offset), _orientation(orientation), _weapon(weapon)
{

}

WeaponSlot::WeaponSlot(WeaponSlot const &instance)
{
	*this = instance;
}

WeaponSlot::~WeaponSlot(void)
{
	
}

WeaponSlot &	WeaponSlot::operator=(WeaponSlot const &rhs)
{
	this->_offset = rhs._offset;
	this->_orientation = rhs._orientation;
	return *this;
}

AbstractWeapon	*WeaponSlot::getWeapon(void)
{
	return (this->_weapon);
}

Vec2			WeaponSlot::getOffset(void)
{
	return (this->_offset);
}

Vec2			WeaponSlot::getOrientation(void)
{
	return (this->_orientation);
}

