/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:25:42 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 11:37:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYFACTORY_HPP
# define ENTITYFACTORY_HPP

#define MAX_BLUEPRINT 5
#define MAX_ENEMIES 1

#include "AbstractEnemy.hpp"
#include "Alien.hpp"

# define NB_ENEMIES 1

enum {
	ALIEN,
	SPACESHIP,
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
    
	    AbstractEnemy*          createEnemy(Vec2 pos, Vec2 dir);
        AbstractEnemy*          createRandomEnemy(Vec2 pos, Vec2 dir);
        Player*                 createPlayerAtMapCreation();


        AbstractEnemy*          createAlien(Vec2 pos, Vec2 dir);
        Player*                 createPlayer(Vec2 pos, Vec2 dir);
        AbstractEntity*			createLife(Vec2 pos, Vec2 dir);
        AbstractEntity*			createCash(Vec2 pos, Vec2 dir);


	private:
        static Blueprint*       _blueprints[NB_ENTITIES];
        static std::string      _blueprintsId[NB_ENTITIES];
        static std::string      _enemyTypes[NB_ENEMIES];

        static AbstractEnemy*	(EntityFactory::*_createEnemyFunc[NB_ENEMIES])(Vec2 pos, Vec2 dir);
        static AbstractEntity*	(EntityFactory::*_createEntityFunc[NB_ENTITIES])(Vec2 pos, Vec2 dir);
};

#endif