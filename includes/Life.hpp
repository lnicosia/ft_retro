/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Life.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:35:05 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 18:31:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_HPP
# define LIFE_HPP

# include <iostream>
# include "Vec2.hpp"
# include "AbstractPickup.hpp"

class Life : public AbstractPickup
{
	public:
		Life(void);
		Life(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		Life(Life const &instance);
		Life &operator=(Life const &rhs);
		virtual ~Life(void);
		virtual int		getColor() const;

		virtual void onCollide(Player &player);
	private:

};
#endif