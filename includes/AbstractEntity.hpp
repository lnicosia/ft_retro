/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEntity.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:01:38 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 01:10:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTENTITY_HPP
# define ABSTRACTENTITY_HPP

# include <iostream>
# include "Vec2.hpp"
# include "Blueprint.hpp"

class Blueprint;
class Map;

class AbstractEntity
{
	public:

		AbstractEntity(void);
		AbstractEntity(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		AbstractEntity(AbstractEntity const &instance);
		AbstractEntity &operator=(AbstractEntity const &rhs);
		virtual ~AbstractEntity(void);
		void render(void) const;

		virtual void update(Map &map); //= 0;

		virtual bool shouldBeCleaned() = 0;
	
		Vec2		getPosition(void) const;
		Vec2		getOrientation(void) const;
		Vec2		getDirection(void) const;
		Blueprint*	getBlueprint(void) const;
	
		bool	isOnScreen(void);
		bool	isOnScreen(void) const;
		void	setPosition(Vec2 pos);
		void	setOrientation(Vec2 orientation);
		void	setDirection(Vec2 dir);
		void	setBlueprint(Blueprint*);

	private:
		Vec2		_position;
		Vec2		_direction;
		Blueprint	*_blueprint;

};
#endif