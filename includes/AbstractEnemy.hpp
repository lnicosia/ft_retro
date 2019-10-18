/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractEnemy.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:20:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 17:36:42 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTENEMY_HPP
# define ABSTRACTENEMY_HPP

# include <iostream>
# include "Vec2.hpp"
# include "AbstractForegroundEntity.hpp"

class Blueprint;

class AbstractEnemy : public AbstractForegroundEntity
{
	public:
		AbstractEnemy(void);
		AbstractEnemy(Vec2 pos, Vec2 dir, Blueprint blueprint, int health, int scoreOnDeath);
		AbstractEnemy(AbstractEnemy const &instance);
		AbstractEnemy &operator=(AbstractEnemy const &rhs);
		~AbstractEnemy(void);

		int getHealth(void);
		int getScoreOnDeath(void);
	
	private:
		int _health;
		int _scoreOnDeath;
};
#endif