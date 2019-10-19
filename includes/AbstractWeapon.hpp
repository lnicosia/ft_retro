/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:46:02 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 17:03:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTWEAPON_HPP
# define ABSTRACTWEAPON_HPP

# include <iostream>
# include "AbstractProjectile.hpp"
# include "WeaponSlot.hpp"

class Map;
class Player;
class AbstractEnemy;
class WeaponSlot;

class AbstractWeapon
{
	public:
		AbstractWeapon(int fireRate, AbstractProjectile *projectile);
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

		AbstractProjectile *_projectile;
};

std::ostream &operator<<(std::ostream &o, AbstractWeapon const &instance);
#endif