/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEnemy.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:20:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 10:56:53 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTENEMY_HPP
# define ABSTRACTENEMY_HPP

# include <iostream>
# include "Vec2.hpp"
# include "AbstractForegroundEntity.hpp"
# include "AbstractWeapon.hpp"
# include "WeaponSlot.hpp"
# include "IShooter.hpp"

class Blueprint;

class AbstractEnemy : public AbstractForegroundEntity, public IShooter
{
	public:
		AbstractEnemy(void);
		AbstractEnemy(Vec2 pos, Vec2 dir, Blueprint blueprint, int health, int scoreOnDeath, WeaponSlot ws);
		AbstractEnemy(AbstractEnemy const &instance);
		AbstractEnemy &operator=(AbstractEnemy const &rhs);
		virtual ~AbstractEnemy(void);
		virtual void shoot(Map &map);

		int				getHealth(void);
		int				getScoreOnDeath(void);
		WeaponSlot		getSlot(void);
		int				getScoreOnDeath(void);

	private:
		int				_health;
		int				_scoreOnDeath;
		WeaponSlot		_weaponSlot;

};
#endif