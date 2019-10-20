/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEnemy.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:20:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 14:35:00 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTENEMY_HPP
# define ABSTRACTENEMY_HPP

# include <iostream>
# include "Vec2.hpp"
# include "AbstractForegroundEntity.hpp"
# include "WeaponSlot.hpp"
# include "IShooter.hpp"

class Blueprint;
class Map;
class WeaponSlot;

class AbstractEnemy : public AbstractForegroundEntity, public IShooter
{
	public:
		AbstractEnemy(void);
		AbstractEnemy(Vec2 pos, Vec2 dir, Blueprint *blueprint, int health, int scoreOnDeath, WeaponSlot ws, float minFireRate);
		AbstractEnemy(AbstractEnemy const &instance);
		AbstractEnemy &operator=(AbstractEnemy const &rhs);
		
		void	takeDamage(int damage, Map &map);
		virtual ~AbstractEnemy(void);

		int				getHealth(void);
		int				getScoreOnDeath(void);
		WeaponSlot		getSlot(void);
		bool			isDead(void);
		void			die(Player &player);
		void			drop(Map &map);

		virtual void	update(Map &map);
		virtual void	shoot(Map &map);
		virtual bool	shouldBeCleaned(void);
		virtual void	onCollide(Player &player);
		virtual void	onCollide(AbstractEnemy &enemy, Map &map);
		float			getMinFireRate(void);
		
	private:

		int				_health;
		int				_scoreOnDeath;
		WeaponSlot		_weaponSlot;
		bool			_dead;
		float			_minFireRate;

};
#endif