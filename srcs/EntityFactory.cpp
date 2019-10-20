/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:37:54 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 12:11:13 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityFactory.hpp"
#include "Player.hpp"
#include "LaserThrower.hpp"
#include "Life.hpp"
#include "Cash.hpp"
#include <ncurses.h>

EntityFactory::EntityFactory(void)
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
    new Blueprint("assets/ship.ascii"), 
    new Blueprint("assets/carré.ascii"),
    new Blueprint("assets/life.ascii"),
    new Blueprint("assets/cash.ascii"),
};

std::string EntityFactory::_blueprintsId[NB_ENTITIES] =
{
    "droite",
};

std::string EntityFactory::_enemyTypes[MAX_ENEMIES] =
{
    "alien",
};


AbstractEnemy*	(EntityFactory::*EntityFactory::_createEnemyFunc[NB_ENEMIES])(Vec2 pos, Vec2 dir) = 
{
	&EntityFactory::createAlien,
};

AbstractEntity*	(EntityFactory::*EntityFactory::_createEntityFunc[NB_ENTITIES])(Vec2 pos, Vec2 dir) = 
{
	(AbstractEntity *(EntityFactory::*)(Vec2 pos, Vec2 dir))&EntityFactory::createAlien,
	(AbstractEntity *(EntityFactory::*)(Vec2 pos, Vec2 dir))&EntityFactory::createPlayer,
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
    while (i < MAX_ENTITIES)
    {
        if (!this->_enemyTypes[i].compare(type))
            return (this->*EntityFactory::_createEntityFunc[i])(pos, dir);
        i++;
    }
    return 0;
}

AbstractEnemy*	EntityFactory::createEnemy(Vec2 pos, Vec2 dir)
{
	(void)pos;
	(void)dir;
	return 0;
}

AbstractEnemy*  EntityFactory::createAlien(Vec2 pos, Vec2 dir)
{
  return new Alien(pos, dir, this->_blueprints[ALIEN]);
}

AbstractEntity	*EntityFactory::createLife(Vec2 pos, Vec2 dir)
{
	return new Life(pos, dir, this->_blueprints[LIFE]);
}


AbstractEntity	*EntityFactory::createCash(Vec2 pos, Vec2 dir)
{
	return new Cash(pos, dir, this->_blueprints[CASH]);
}


Player*     EntityFactory::createPlayer(Vec2 pos, Vec2 dir)
{
	return new Player(pos, dir, this->_blueprints[SPACESHIP]);
}

AbstractEnemy*	EntityFactory::createRandomEnemy(Vec2 pos, Vec2 dir)
{
	(void)pos;
	(void)dir;
	//random index ...
	return 0;
}

Player*     EntityFactory::createPlayerAtMapCreation()
{
	Player *player = new Player(this->_blueprints[SPACESHIP]);
    player->setPosition(Vec2(COLS / 2 - player->getBlueprint()->getSizeX(), LINES - player->getBlueprint()->getSizeY()));
    return player;
}
