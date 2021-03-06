/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractForegroundEntity.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:16:07 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 18:36:37 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOREGROUNDABSTRACTENTITY_HPP
# define FOREGROUNDABSTRACTENTITY_HPP

# include <iostream>
# include "AbstractEntity.hpp"
// # include "AbstractEnemy.hpp"
// # include "Player.hpp"

//collision type:

//player - pickups
//player - enemies
//player - enemy Projectiles
//player own lasers - enemies

//-> will need a list of

// pickups, enemies, enemy projectiles, own projectiles

class Map;
class Player;
class AbstractEnemy;

class AbstractForegroundEntity : public AbstractEntity
{
	public:
		AbstractForegroundEntity(void);
		AbstractForegroundEntity(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		AbstractForegroundEntity(AbstractForegroundEntity const &instance);
		AbstractForegroundEntity &operator=(AbstractForegroundEntity const &rhs);
		virtual ~AbstractForegroundEntity(void);
		virtual int		getColor() const;

		virtual void onCollide(Player &player) = 0;
		virtual void onCollide(AbstractEnemy &enemy, Map &map) = 0;


	private:
		
};
#endif