/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:42:08 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:25:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityFactory.hpp"
#include "Player.hpp"
#include "LaserThrower.hpp"
#include "BackgroundEntity.hpp"
#include "RegularMissile.hpp"
#include "CrappyMissile.hpp"
#include "Moon.hpp"
#include "Star1.hpp"
#include "Star2.hpp"
#include "Star3.hpp"
#include "Life.hpp"
#include "Boss.hpp"
#include "Cash.hpp"
#include <ncurses.h>
       
EntityFactory::EntityFactory()
{
	
}

EntityFactory::EntityFactory(EntityFactory const &instance)
{
	*this = instance;
}

EntityFactory::~EntityFactory(void)
{
	
}

	// ALIEN,
	// ASTEROID,
	// SPACESHIP,
	// REGULAR_MISSILE,
	// CRAPPY_MISSILE,
	// LIFE,
	// CASH,
	// MOON,
	// STAR1,
	// STAR2,
	// NB_ENTITIES

Blueprint* EntityFactory::_blueprints[NB_ENTITIES] =
{
    new Blueprint("assets/alien.ascii"),
    new Blueprint("assets/asteroid.ascii"),
    new Blueprint("assets/boss.ascii"),
    new Blueprint("assets/ship.ascii"), 
    new Blueprint("assets/regularMissile.ascii"),
    new Blueprint("assets/crappyMissile.ascii"),
    new Blueprint("assets/life.ascii"),
    new Blueprint("assets/cash.ascii"),
    new Blueprint("assets/moon.ascii"),
    new Blueprint("assets/star.ascii"),
    new Blueprint("assets/star2.ascii"),
    new Blueprint("assets/star3.ascii"),
};

std::string EntityFactory::_entityTypes[NB_ENTITIES] =
{
    "alien",
    "asteroid",
    "boss",
	"player",
    "regular missile",
    "crappy missile",
	"life",
	"cash",
	"moon",
	"star1",
	"star2",
	"star3",
};

AbstractEntity*    (EntityFactory::*EntityFactory::_createFunc[NB_ENTITIES])(Vec2 pos, Vec2 dir) = 
{
	&EntityFactory::createAlien,
	&EntityFactory::createAsteroid,
	&EntityFactory::createBoss,
	&EntityFactory::createPlayer,
	&EntityFactory::createRegularMissile,
	&EntityFactory::createCrappyMissile,
	&EntityFactory::createLife,
	&EntityFactory::createCash,
	&EntityFactory::createMoon,
	&EntityFactory::createStar1,
	&EntityFactory::createStar2,
	&EntityFactory::createStar3,
};

AbstractEntity*    (EntityFactory::*EntityFactory::_createBackgroundFunc[NB_BACKGROUND])(Vec2 pos, Vec2 dir) = 
{
	&EntityFactory::createMoon,
	&EntityFactory::createStar1,
	&EntityFactory::createStar2,
	&EntityFactory::createStar3,
};

EntityFactory &	EntityFactory::operator=(EntityFactory const &rhs)
{
	(void)rhs;
    return *this;
}

AbstractEntity*	EntityFactory::createEntity(std::string type, Vec2 pos, Vec2 dir)
{
    size_t  i = 0;
    while (i < NB_ENTITIES)
    {
        if (!this->_entityTypes[i].compare(type))
            return (this->*_createFunc[i])(pos, dir);
        i++;
    }
    return 0;
}

AbstractEntity*	EntityFactory::createEnemy(Vec2 pos, Vec2 dir)
{
	(void)pos;
	(void)dir;
	return 0;
}

AbstractEntity*  EntityFactory::createAlien(Vec2 pos, Vec2 dir)
{
  return new Alien(pos, dir, this->_blueprints[ALIEN]);
}

AbstractEntity*  EntityFactory::createAsteroid(Vec2 pos, Vec2 dir)
{
    Asteroid* asteroid = new Asteroid(pos, dir, this->_blueprints[ASTEROID]);
	return asteroid;
}
AbstractEntity	*EntityFactory::createLife(Vec2 pos, Vec2 dir)
{
	return new Life(pos, dir, this->_blueprints[LIFE]);
}

AbstractEntity* EntityFactory::createRegularMissile(Vec2 pos, Vec2 dir)
{
    RegularMissile *missile = new RegularMissile(pos, dir, this->_blueprints[REGULAR_MISSILE]);
    return missile;
}

AbstractEntity*	EntityFactory::createRandomEnemy(Vec2 pos, Vec2 dir)
{
	int rando = random() % NB_ENEMIES;
	if (rando == BOSS)
	{
		if (random() % 100 > 80)
		{
			AbstractEntity *boss = (this->*_createFunc[BOSS])(pos, dir);
			boss->setPosition(Vec2(COLS / 2 - boss->getBlueprint()->getSizeX(), pos.getY()));
			return boss;
		}
		else
    		return (this->*_createFunc[ALIEN])(pos, dir);
	}
    return (this->*_createFunc[rando])(pos, dir);
}

AbstractEntity	*EntityFactory::createCash(Vec2 pos, Vec2 dir)
{
	return new Cash(pos, dir, this->_blueprints[CASH]);
}

AbstractEntity *EntityFactory::createPlayer(Vec2 pos, Vec2 dir)
{
	return new Player(pos, dir, this->_blueprints[SPACESHIP]);
}

AbstractEntity	*EntityFactory::createCrappyMissile(Vec2 pos, Vec2 dir)
{
	return new CrappyMissile(pos, dir, this->_blueprints[CRAPPY_MISSILE]);
}

AbstractEntity	*EntityFactory::createMoon(Vec2 pos, Vec2 dir)
{
	return new Moon(pos, dir, this->_blueprints[MOON]);
}

AbstractEntity	*EntityFactory::createStar1(Vec2 pos, Vec2 dir)
{
	return new Star1(pos, dir, this->_blueprints[STAR1]);
}

AbstractEntity	*EntityFactory::createStar2(Vec2 pos, Vec2 dir)
{
	return new Star2(pos, dir, this->_blueprints[STAR2]);
}

AbstractEntity	*EntityFactory::createStar3(Vec2 pos, Vec2 dir)
{
	return new Star3(pos, dir, this->_blueprints[STAR3]);
}

AbstractEntity	*EntityFactory::createBoss(Vec2 pos, Vec2 dir)
{
	return new Boss(pos, dir, this->_blueprints[BOSS]);
}

AbstractEntity	*EntityFactory::createRandomBackground(Vec2 pos, Vec2 dir)
{
	return (this->*_createBackgroundFunc[rand() % NB_BACKGROUND])(pos, dir);
}

Player*     EntityFactory::createPlayerAtMapCreation()
{
	Player *player = new Player(this->_blueprints[SPACESHIP]);
    player->setPosition(Vec2(COLS / 2 - player->getBlueprint()->getSizeX(), LINES - player->getBlueprint()->getSizeY()));
    return player;
}