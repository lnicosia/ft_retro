/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:33:41 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 18:25:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "Player.hpp"
# include "AbstractPickup.hpp"
# include "EntityContainer.hpp"
# include "EntityFactory.hpp"

//collision type:

//player - pickups
//player - enemies
//player - enemy Projectiles
// (UPDATE PLAYER)

//player own projectile - enemies
//(UPDATE PROJECTILE)

//-> will need a list of

// pickups, enemies, enemy projectiles, own projectiles

class Map
{
	public:
		Map(void);
		Map(Map const &instance);
		Map &operator=(Map const &rhs);
		~Map(void);
		Player	&getPlayer(void);
		void	update(void);
		void	clean(void);
		void	render(void) const;

	private:

		EntityFactory		_factory;

		EntityContainer		_background;
		EntityContainer		_enemies;
		EntityContainer 	_playerProjectiles;
		EntityContainer		_enemiesProjectiles;
		EntityContainer		_pickups;

		Player*				_player;
};

std::ostream &operator<<(std::ostream &o, Map const &instance);
#endif