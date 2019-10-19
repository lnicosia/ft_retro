/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:37:54 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 00:37:40 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityFactory.hpp"
#include "Player.hpp"
#include "LaserThrower.hpp"
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

Blueprint* EntityFactory::_blueprints[MAX_BLUEPRINT] =
{
    new Blueprint("assets/ship.ascii"),
    new Blueprint("assets/carré.ascii"),
    new Blueprint("assets/droite.ascii"),
    new Blueprint("assets/créneauDroite.ascii"),
    new Blueprint("assets/créneauGauche.ascii")
};

std::string EntityFactory::_blueprintsId[MAX_BLUEPRINT] =
{
    "droite",
};

std::string EntityFactory::_enemyTypes[MAX_ENEMIES] =
{
    "alien",
};

AbstractEnemy*    (EntityFactory::*EntityFactory::_createFunc[1])(Vec2 pos, Vec2 dir) = 
{
	&EntityFactory::createAlien,
};

EntityFactory &	EntityFactory::operator=(EntityFactory const &rhs)
{
	(void)rhs;
    return *this;
}

AbstractEntity*	EntityFactory::createEntity(std::string type, Vec2 pos, Vec2 dir)
{
    size_t  i = 0;
    while (i < MAX_ENEMIES)
    {
        if (!this->_enemyTypes[i].compare(type))
            return (this->*_createFunc[i])(pos, dir);
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
    // Alien* alien = new Alien(Vec2(COLS / 2 - this->_blueprints[1]->getSizeX() / 2, 0),
    //     Vec2(0, 1), this->_blueprints[1], 50, 50, WeaponSlot());
    Alien* alien = new Alien(pos, dir, this->_blueprints[1]);
	return alien;
}



AbstractEnemy*	EntityFactory::createRandomEnemy(Vec2 pos, Vec2 dir)
{
	(void)pos;
	(void)dir;
	return 0;
}

Player*     EntityFactory::createPlayer()
{
	Player *player = new Player(this->_blueprints[0]);
    player->setPosition(Vec2(COLS / 2 - player->getBlueprint()->getSizeX(), LINES - player->getBlueprint()->getSizeY()));
    return player;
}