/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:37:54 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 13:06:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityFactory.hpp"
#include "Player.hpp"
#include "LaserThrower.hpp"
#include "RegularMissile.hpp"
#include "Life.hpp"
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

Blueprint* EntityFactory::_blueprints[NB_ENTITIES] =
{
    new Blueprint("assets/carré.ascii"),
    new Blueprint("assets/droite.ascii"),
    new Blueprint("assets/ship.ascii"), 
    new Blueprint("assets/regularMissile.ascii"),
    new Blueprint("assets/life.ascii"),
    new Blueprint("assets/cash.ascii"),
};

std::string EntityFactory::_entityTypes[NB_ENTITIES] =
{
    "alien",
    "asteroid",
	"player",
    "regular missile",
	"life",
	"cash"
};

AbstractEntity*    (EntityFactory::*EntityFactory::_createFunc[NB_ENTITIES])(Vec2 pos, Vec2 dir) = 
{
	&EntityFactory::createAlien,
	&EntityFactory::createAsteroid,
	&EntityFactory::createPlayer,
	&EntityFactory::createRegularMissile,
	&EntityFactory::createLife,
	&EntityFactory::createCash
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
	exit(1);
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
    return (this->*_createFunc[rand() % NB_ENEMIES])(pos, dir);
}

AbstractEntity	*EntityFactory::createCash(Vec2 pos, Vec2 dir)
{
	return new Cash(pos, dir, this->_blueprints[CASH]);
}

AbstractEntity *EntityFactory::createPlayer(Vec2 pos, Vec2 dir)
{
	return new Player(pos, dir, this->_blueprints[SPACESHIP]);
}

Player*     EntityFactory::createPlayerAtMapCreation()
{
	Player *player = new Player(this->_blueprints[SPACESHIP]);
    player->setPosition(Vec2(COLS / 2 - player->getBlueprint()->getSizeX(), LINES - player->getBlueprint()->getSizeY()));
    return player;
}
