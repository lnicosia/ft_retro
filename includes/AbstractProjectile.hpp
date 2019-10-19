/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractProjectile.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:57:41 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 15:59:33 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTPROJECTILE_HPP
# define ABSTRACTPROJECTILE_HPP

# include <iostream>
# include "Vec2.hpp"
# include "AbstractForegroundEntity.hpp"

class Blueprint;
class Map;

class AbstractProjectile : public AbstractForegroundEntity
{
	public:
		AbstractProjectile(void);
		AbstractProjectile(Vec2 pos, Vec2 dir, Blueprint blueprint, int damage);
		AbstractProjectile(AbstractProjectile const &instance);
		AbstractProjectile &operator=(AbstractProjectile const &rhs);
		~AbstractProjectile(void);
		virtual void update(Map &map) = 0;

		int getDamage(void);
	private:
		int _damage;
};
#endif