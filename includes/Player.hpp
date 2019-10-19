/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:41:08 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 14:50:18 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include "AbstractForegroundEntity.hpp"
# include "AbstractWeapon.hpp"
# include "Map.hpp"
# include "IShooter.hpp"

class Player : public AbstractForegroundEntity, public IShooter
{
	public:
		Player(void);
		Player(Player const &instance);
		Player &operator=(Player const &rhs);
		virtual ~Player(void);
		virtual void process(void);
		virtual void	shoot(Map &map);
		virtual void	update(Map &map);
		WeaponSlot		getWeaponSlot(int i);
		int				getInput(void);
		void			setInput(int input);

	private:
		WeaponSlot		_weaponSlots[4];
		int				_input;
};

std::ostream &operator<<(std::ostream &o, Player const &instance);
#endif