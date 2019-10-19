/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:33:41 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 09:56:55 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "AbstractForegroundEntity.hpp"
# include "Player.hpp"

# define MAX_ENTITIES 500

class Map
{
	public:
		Map(void);
		Map(Map const &instance);
		Map &operator=(Map const &rhs);
		~Map(void);
		Player &getPlayer(void);
		void	process(void);
		void	render(void) const;

	private:

		AbstractEntity				*_backgroundEntities[MAX_ENTITIES];
		int							_nbBgEntities;

//		AbstractForegroundEntity	*_foregroundEntities[MAX_ENTITIES];

//		AbstractForegroundEntity	*_backgroundEntities[MAX_ENTITIES];
//		int							_nbFgEntities;
		Player						_player;
};

std::ostream &operator<<(std::ostream &o, Map const &instance);
#endif