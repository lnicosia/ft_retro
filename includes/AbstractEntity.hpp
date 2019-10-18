/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEntity.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:01:38 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 16:51:29 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTENTITY_HPP
# define ABSTRACTENTITY_HPP

# include <iostream>
# include "Vec2.hpp"

class Blueprint;

class AbstractEntity
{
	public:
		AbstractEntity(Vec2 pos, Vec2 dir, Blueprint &blueprint);
		AbstractEntity(AbstractEntity const &instance);
		AbstractEntity &operator=(AbstractEntity const &rhs);
		virtual ~AbstractEntity(void);
		virtual void process() = 0;
		void render(void) const;

		Vec2		getPosition(void);
		Vec2		getDirection(void);
		Blueprint	getBlueprint(void);
	
		void	setPosition(Vec2 pos);
		void	setDirection(Vec2 dir);

	private:
		Vec2	_position;
		Vec2	_direction;
		Blueprint	&_blueprint;

};

std::ostream &operator<<(std::ostream &o, AbstractEntity const &instance);
#endif