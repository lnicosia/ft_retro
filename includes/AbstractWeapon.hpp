/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:46:02 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 18:49:23 by ldedier          ###   ########.fr       */
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
		AbstractWeapon(void);
		AbstractWeapon(int fireRate, std::string projectileName);
		AbstractWeapon(AbstractWeapon const &instance);
		AbstractWeapon &operator=(AbstractWeapon const &rhs);
		virtual ~AbstractWeapon(void);
		virtual void processBeShot(AbstractEntity &entity, WeaponSlot ws, EntityContainer &container, Map &map) = 0;

		virtual void beShot(AbstractEnemy &enemy, WeaponSlot ws, Map &map);
		virtual void beShot(Player &player, WeaponSlot ws, Map &map);
	private:
		int _fireRate;
		std::string _projectileName;
};

std::ostream &operator<<(std::ostream &o, AbstractWeapon const &instance);
#endif