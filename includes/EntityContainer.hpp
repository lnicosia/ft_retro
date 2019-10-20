/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityContainer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:12:33 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 17:16:40 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYCONTAINER_HPP
# define ENTITYCONTAINER_HPP

# define MAX_ENTITIES 500

# include <iostream>
# include "AbstractEntity.hpp"

class AbstractEntity;

class EntityContainer
{
	public:
		EntityContainer(void);
		EntityContainer(EntityContainer const &instance);
		EntityContainer &operator=(EntityContainer const &rhs);
		~EntityContainer(void);

		void update(Map &map) const;
		void clean(void);
		bool collide(AbstractEntity &entity);
		void render(void) const;
		void add(AbstractEntity *entity);

		int				getSize(void);
		AbstractEntity	*getEntity(int);

	private:

		void _shiftContainer(size_t index);
		AbstractEntity				*_entities[MAX_ENTITIES];
		size_t						_size;


};

std::ostream &operator<<(std::ostream &o, EntityContainer const &instance);
#endif