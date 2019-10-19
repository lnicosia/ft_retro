/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:46:02 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 18:02:00 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTWEAPON_HPP
# define ABSTRACTWEAPON_HPP

# include <iostream>
# include "AbstractProjectile.hpp"
# include "WeaponSlot.hpp"
# include "EntityContainer.hpp"

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
		virtual void processBeShot(AbstractEntity &entity, WeaponSlot ws, EntityContainer &container) = 0;

		virtual void beShot(AbstractEnemy &enemy, WeaponSlot ws, Map &map);
		virtual void beShot(Player &player, WeaponSlot ws, Map &map);
	private:
		AbstractWeapon(void);
		int _fireRate;

		AbstractProjectile *_projectile;
};

std::ostream &operator<<(std::ostream &o, AbstractWeapon const &instance);
#endif