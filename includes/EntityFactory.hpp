/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:25:42 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 12:40:37 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYFACTORY_HPP
# define ENTITYFACTORY_HPP

#include "AbstractEnemy.hpp"
#include "Alien.hpp"
#include "Asteroid.hpp"

# define NB_ENEMIES 2

enum {
	ALIEN,
	ASTEROID,
	SPACESHIP,
	REGULAR_MISSILE,
	LIFE,
	CASH,
	NB_ENTITIES
};

class EntityFactory
{
	public:
		EntityFactory(void);
		EntityFactory(EntityFactory const &instance);
		EntityFactory &operator=(EntityFactory const &rhs);
		~EntityFactory(void);
	
        AbstractEntity*         createEntity(std::string type, Vec2 pos, Vec2 dir);
        AbstractEntity*         createEnemy(Vec2 pos, Vec2 dir);
        AbstractEntity*         createRandomEnemy(Vec2 pos, Vec2 dir);

		Player*                 createPlayerAtMapCreation(void);
        
		AbstractEntity*         createAlien(Vec2 pos, Vec2 dir);
        AbstractEntity*         createAsteroid(Vec2 pos, Vec2 dir);
        AbstractEntity*         createRegularMissile(Vec2 pos, Vec2 dir);
        AbstractEntity*			createLife(Vec2 pos, Vec2 dir);
        AbstractEntity*			createCash(Vec2 pos, Vec2 dir);
		AbstractEntity*         createPlayer(Vec2 pos, Vec2 dir);

	private:
        static Blueprint*       _blueprints[NB_ENTITIES];
        static std::string      _entityTypes[NB_ENTITIES];
		
        static AbstractEntity*  (EntityFactory::*_createFunc[NB_ENTITIES])(Vec2 pos, Vec2 dir);
};

#endif