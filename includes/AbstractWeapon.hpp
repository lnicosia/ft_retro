/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:46:02 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 11:09:42 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTWEAPON_HPP
# define ABSTRACTWEAPON_HPP

# include <iostream>
# include "AbstractForegroundEntity.hpp"
# include "AbstractProjectile.hpp"
# include "AbstractEnemy.hpp"
# include "Map.hpp"

class AbstractWeapon
{
	public:
		AbstractWeapon(int fireRate, AbstractProjectile &projectile);
		AbstractWeapon(AbstractWeapon const &instance);
		AbstractWeapon &operator=(AbstractWeapon const &rhs);
		virtual ~AbstractWeapon(void);

		void processBeShot(AbstractEnemy &enemy, WeaponSlot ws, Map &map);
		void processBeShot(Player &player, WeaponSlot ws, Map &map);
		
		virtual void beShot(AbstractEnemy &enemy, WeaponSlot ws, Map &map);
		virtual void beShot(Player &player, WeaponSlot ws, Map &map);
	private:
		AbstractWeapon(void);
		int _fireRate;
		int _level;

		AbstractProjectile &laser;
};

std::ostream &operator<<(std::ostream &o, AbstractWeapon const &instance);
#endif