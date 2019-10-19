/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractProjectile.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:57:41 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 09:53:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTPROJECTILE_HPP
# define ABSTRACTPROJECTILE_HPP

# include <iostream>
# include "Vec2.hpp"

class Blueprint;

class AbstractProjectile
{
	public:
		AbstractProjectile(void);
		AbstractProjectile(Vec2 pos, Vec2 dir, Blueprint blueprint, int damage);
		AbstractProjectile(AbstractProjectile const &instance);
		AbstractProjectile &operator=(AbstractProjectile const &rhs);
		~AbstractProjectile(void);

	private:
		int _damage;
};

std::ostream &operator<<(std::ostream &o, AbstractProjectile const &instance);
#endif