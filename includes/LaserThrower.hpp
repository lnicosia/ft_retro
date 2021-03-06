/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LaserThrower.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:14:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 16:26:27 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LASERTHROWER_HPP
# define LASERTHROWER_HPP

# include <iostream>
# include "AbstractWeapon.hpp"
# include "Map.hpp"

class LaserThrower: public AbstractWeapon
{
	public:
		LaserThrower(void);
		LaserThrower(LaserThrower const &instance);
		LaserThrower &operator=(LaserThrower const &rhs);
		virtual ~LaserThrower(void);
		// virtual void processBeShot(AbstractEntity &entity, WeaponSlot ws, EntityContainer &container, Map &map);
		

	private:

};
#endif