/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CrappyThrower.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:16:56 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 15:39:40 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRAPPYTHROWER_HPP
# define CRAPPYTHROWER_HPP

# include <iostream>
#include "AbstractEnemy.hpp"

class CrappyThrower : public AbstractWeapon
{
	public:
		CrappyThrower(void);
		CrappyThrower(CrappyThrower const &instance);
		CrappyThrower &operator=(CrappyThrower const &rhs);
		~CrappyThrower(void);
		// virtual void processBeShot(AbstractEntity &entity, WeaponSlot ws, EntityContainer &container, Map &map);

	private:

};
#endif