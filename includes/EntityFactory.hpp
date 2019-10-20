/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:25:42 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 08:57:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYFACTORY_HPP
# define ENTITYFACTORY_HPP

#define MAX_BLUEPRINT 5
#define MAX_ENEMIES 2

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
        AbstractEnemy*          createEnemy(Vec2 pos, Vec2 dir);
        AbstractEnemy*          createRandomEnemy(Vec2 pos, Vec2 dir);
        Player*                 createPlayer(void);
        AbstractEnemy*          createAlien(Vec2 pos, Vec2 dir);
        AbstractEnemy*          createAsteroid(Vec2 pos, Vec2 dir);

		static EntityFactory	*_instance;

	private:
        static Blueprint*       _blueprints[MAX_BLUEPRINT];
        static std::string      _blueprintsId[MAX_BLUEPRINT];
        static std::string      _enemyTypes[MAX_ENEMIES];
        static AbstractEnemy*  (EntityFactory::*_createFunc[MAX_ENEMIES])(Vec2 pos, Vec2 dir);

};

#endif