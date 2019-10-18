/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractWeapon.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:46:02 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 15:00:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTWEAPON_HPP
# define ABSTRACTWEAPON_HPP

# include <iostream>
# include "AbstractForegroundEntity.hpp"
# include "AbstractProjectile.hpp"

class AbstractWeapon
{
	public:
		AbstractWeapon(void);
		AbstractWeapon(int fireRate, int damage, AbstractForegroundEntity &projectile);
		AbstractWeapon(AbstractWeapon const &instance);
		AbstractWeapon &operator=(AbstractWeapon const &rhs);
		virtual ~AbstractWeapon(void);
		virtual void fire() = 0;
		virtual void upgrade() = 0;
		
	private:
		int _fireRate;
		int _damage;
		int _level;

		AbstractProjectile &laser;
};

std::ostream &operator<<(std::ostream &o, AbstractWeapon const &instance);
#endif