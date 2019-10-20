/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackgroundEntity.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:19:55 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 16:23:16 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUNDENTITY_HPP
# define BACKGROUNDENTITY_HPP

# include <iostream>
#include "Map.hpp"
#include "Vec2.hpp"

class BackgroundEntity : public AbstractEntity
{
	public:
		BackgroundEntity(void);
		BackgroundEntity(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		BackgroundEntity(BackgroundEntity const &instance);
		BackgroundEntity &operator=(BackgroundEntity const &rhs);
		virtual ~BackgroundEntity(void);

		virtual void onCollide(Player &player);
		virtual void onCollide(AbstractEnemy &enemy, Map &map);
		virtual bool shouldBeCleaned(void);

	private:

};
#endif