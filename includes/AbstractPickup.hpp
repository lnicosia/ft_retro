/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractPickup.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 08:53:33 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 08:54:25 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTPICKUP_HPP
# define ABSTRACTPICKUP_HPP

# include <iostream>
# include "AbstractForegroundEntity.hpp"

class AbstractPickup : public AbstractForegroundEntity
{
	public:
		AbstractPickup(void);
		AbstractPickup(Vec2 pos, Vec2 dir, Blueprint blueprint);
		AbstractPickup(AbstractPickup const &instance);
		AbstractPickup &operator=(AbstractPickup const &rhs);
		~AbstractPickup(void);

	private:

};

std::ostream &operator<<(std::ostream &o, AbstractPickup const &instance);
#endif