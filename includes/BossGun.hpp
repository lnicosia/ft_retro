/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BossGun.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:47:01 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:52:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSSGUN_HPP
# define BOSSGUN_HPP

# include <iostream>
# include "AbstractEnemy.hpp"

class BossGun : public AbstractWeapon
{
	public:
		BossGun(void);
		BossGun(BossGun const &instance);
		BossGun &operator=(BossGun const &rhs);
		~BossGun(void);
		virtual void processBeShot(AbstractEntity &entity, WeaponSlot &ws, EntityContainer &container, Map &map);
	
	private:

};
#endif