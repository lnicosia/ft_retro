/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WeaponFactory.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:12:49 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 18:42:48 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONFACTORY_HPP
# define WEAPONFACTORY_HPP

# include <iostream>
# include "AbstractWeapon.hpp"


# define NB_WEAPONS 1

class WeaponFactory
{
	public:
		WeaponFactory(void);
		WeaponFactory(WeaponFactory const &instance);
		WeaponFactory &operator=(WeaponFactory const &rhs);
		~WeaponFactory(void);

				
	private:

		AbstractWeapon *_createLaserThrower(void);

		static std::string _factoryIdentifiers[NB_WEAPONS];
		static AbstractWeapon *(WeaponFactory::*_factoryFuncs[NB_WEAPONS])(void);
};
#endif