/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:41:08 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 20:36:13 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include "AbstractForegroundEntity.hpp"
# include "AbstractWeapon.hpp"

class Player : public AbstractForegroundEntity
{
	public:
		Player(void);
		Player(Player const &instance);
		Player &operator=(Player const &rhs);
		virtual ~Player(void);
		virtual void process(void);
	
		AbstractWeapon	*getWeapon(int i);
		int		getBoost(void);
		void	setBoost(int boost);
		int		getInput(void);
		void	setInput(int input);

	private:
		AbstractWeapon *_weapons[2];
		int				_boost;
		int				_input;
};

std::ostream &operator<<(std::ostream &o, Player const &instance);
#endif