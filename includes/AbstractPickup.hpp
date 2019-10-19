/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractPickup.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 08:53:33 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 22:10:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTPICKUP_HPP
# define ABSTRACTPICKUP_HPP

# include <iostream>
# include "AbstractForegroundEntity.hpp"
# include "Map.hpp"

class Map;

class AbstractPickup : public AbstractForegroundEntity
{
	public:
		AbstractPickup(void);
		AbstractPickup(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		AbstractPickup(AbstractPickup const &instance);
		AbstractPickup &operator=(AbstractPickup const &rhs);
		~AbstractPickup(void);

		virtual bool shouldBeCleaned(void);
		virtual void onCollide(AbstractEnemy &enemy);

		virtual void onCollide(Player &player) = 0;


	private:
		bool _used;

};
#endif