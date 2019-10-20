/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cash.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:05:35 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 18:26:59 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASH_HPP
# define CASH_HPP

# include <iostream>
# include "AbstractPickup.hpp"

class Cash : public AbstractPickup
{
	public:
		Cash(void);
		Cash(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		Cash(Cash const &instance);
		Cash &operator=(Cash const &rhs);
		virtual ~Cash(void);
		virtual void onCollide(Player &player);
		virtual int		getColor(void) const;

	private:

};

std::ostream &operator<<(std::ostream &o, Cash const &instance);
#endif