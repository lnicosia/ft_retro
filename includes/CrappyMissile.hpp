/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CrappyMissile.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:23:41 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 15:38:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRAPPYMISSILE_HPP
# define CRAPPYMISSILE_HPP

# include <iostream>
# include "AbstractProjectile.hpp"
# include "Blueprint.hpp"

class CrappyMissile : public AbstractProjectile
{
	public:
		CrappyMissile(void);
		CrappyMissile(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		CrappyMissile(CrappyMissile const &instance);
		CrappyMissile &operator=(CrappyMissile const &rhs);
		~CrappyMissile(void);

	private:

};
#endif