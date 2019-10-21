/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:42:16 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 20:25:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYFACTORY_HPP
# define ENTITYFACTORY_HPP

#include "AbstractEnemy.hpp"
#include "Alien.hpp"
#include "Asteroid.hpp"

# define NB_ENEMIES 3
# define NB_BACKGROUND 4

enum {
	ALIEN,
	ASTEROID,
	BOSS,
	SPACESHIP,
	REGULAR_MISSILE,
	CRAPPY_MISSILE,
	LIFE,
	CASH,
	MOON,
	STAR1,
	STAR2,
	STAR3,
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
		
        AbstractEntity*         createRandomBackground(Vec2 pos, Vec2 dir);

		Player*                 createPlayerAtMapCreation(void);
        
		AbstractEntity*         createAlien(Vec2 pos, Vec2 dir);
        AbstractEntity*         createAsteroid(Vec2 pos, Vec2 dir);
        AbstractEntity*         createRegularMissile(Vec2 pos, Vec2 dir);
        AbstractEntity*         createCrappyMissile(Vec2 pos, Vec2 dir);
        AbstractEntity*			createLife(Vec2 pos, Vec2 dir);
        AbstractEntity*			createCash(Vec2 pos, Vec2 dir);
		AbstractEntity*         createPlayer(Vec2 pos, Vec2 dir);

		AbstractEntity*         createMoon(Vec2 pos, Vec2 dir);
		AbstractEntity*         createStar1(Vec2 pos, Vec2 dir);
		AbstractEntity*         createStar2(Vec2 pos, Vec2 dir);
		AbstractEntity*         createStar3(Vec2 pos, Vec2 dir);

		AbstractEntity*         createBoss(Vec2 pos, Vec2 dir);


	private:
        static Blueprint*       _blueprints[NB_ENTITIES];
        static std::string      _entityTypes[NB_ENTITIES];
		
        static AbstractEntity*  (EntityFactory::*_createFunc[NB_ENTITIES])(Vec2 pos, Vec2 dir);
        static AbstractEntity*  (EntityFactory::*_createBackgroundFunc[NB_BACKGROUND])(Vec2 pos, Vec2 dir);
};

#endif