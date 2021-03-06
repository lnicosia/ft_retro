/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RegularMissile.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:25:33 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 18:27:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGULARMISSILE_HPP
# define REGULARMISSILE_HPP

# include <iostream>
# include "AbstractProjectile.hpp"

class RegularMissile : public AbstractProjectile
{
	public:
		RegularMissile(void);
		RegularMissile(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		RegularMissile(RegularMissile const &instance);
		RegularMissile &operator=(RegularMissile const &rhs);
		virtual ~RegularMissile(void);
		virtual int		getColor(void) const;

	private:

};
#endif