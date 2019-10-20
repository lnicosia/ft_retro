/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WeaponSlot.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:41:06 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 09:53:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONSLOT_HPP
# define WEAPONSLOT_HPP

# include <iostream>
# include "AbstractWeapon.hpp"

class AbstractWeapon;

class WeaponSlot
{
	public:
		WeaponSlot(void);
		WeaponSlot(Vec2 offset, Vec2 orientation, AbstractWeapon *weapon);
		WeaponSlot(Vec2 offset, Vec2 orientation);
		WeaponSlot(WeaponSlot const &instance);
		WeaponSlot &operator=(WeaponSlot const &rhs);
		~WeaponSlot(void);

		AbstractWeapon	*getWeapon(void);
		Vec2			getOffset(void);
		Vec2			getOrientation(void);

	private:
		Vec2			_offset;
		Vec2			_orientation;
		AbstractWeapon	*_weapon;
};
#endif