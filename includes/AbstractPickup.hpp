/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractPickup.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 08:53:33 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 18:59:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTPICKUP_HPP
# define ABSTRACTPICKUP_HPP

# include <iostream>
# include "AbstractForegroundEntity.hpp"
# include "Map.hpp"


class Map;

class AbstractPickup : public AbstractForegroundEntity
{
	public:
		AbstractPickup(void);
		AbstractPickup(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		AbstractPickup(AbstractPickup const &instance);
		AbstractPickup &operator=(AbstractPickup const &rhs);
		~AbstractPickup(void);
		virtual void update(Map &map) = 0;

	private:

};
#endif