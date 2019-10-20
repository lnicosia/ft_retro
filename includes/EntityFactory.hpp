/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:25:42 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 11:30:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYFACTORY_HPP
# define ENTITYFACTORY_HPP

#define MAX_BLUEPRINT 6
#define ENTITY_TYPES 4
#define ENEMY_TYPES 2

#include "AbstractEnemy.hpp"
#include "Alien.hpp"
#include "Asteroid.hpp"

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
        Player*                 createPlayer(void);
        AbstractEntity*         createAlien(Vec2 pos, Vec2 dir);
        AbstractEntity*         createAsteroid(Vec2 pos, Vec2 dir);
        AbstractEntity*         createRegularMissile(Vec2 pos, Vec2 dir);

		static EntityFactory	*_instance;

	private:
        static Blueprint*       _blueprints[MAX_BLUEPRINT];
        static std::string      _blueprintsId[MAX_BLUEPRINT];
        static std::string      _entityTypes[ENTITY_TYPES];
        static AbstractEntity*  (EntityFactory::*_createFunc[ENTITY_TYPES])(Vec2 pos, Vec2 dir);

};

#endif