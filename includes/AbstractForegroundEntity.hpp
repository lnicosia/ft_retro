/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractForegroundEntity.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:16:07 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 18:52:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOREGROUNDABSTRACTENTITY_HPP
# define FOREGROUNDABSTRACTENTITY_HPP

# include <iostream>
# include "AbstractEntity.hpp"


class AbstractForegroundEntity : public AbstractEntity
{
	public:
		AbstractForegroundEntity(void);
		AbstractForegroundEntity(Vec2 pos, Vec2 dir, Blueprint blueprint);
		AbstractForegroundEntity(AbstractForegroundEntity const &instance);
		AbstractForegroundEntity &operator=(AbstractForegroundEntity const &rhs);
		virtual ~AbstractForegroundEntity(void);
		bool collide(const AbstractForegroundEntity &entity);

	private:
		
};
#endif