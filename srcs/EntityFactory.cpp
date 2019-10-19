/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:37:54 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/19 19:03:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityFactory.hpp"
#include "Player.hpp"
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
        new Blueprint("assets/carré.ascii"), new Blueprint("assets/droite.ascii"), new Blueprint("assets/créneauDroite.ascii"),
        new Blueprint("assets/créneauGauche.ascii")
};

std::string EntityFactory::_blueprintsId[MAX_BLUEPRINT] =
{
    "droite",
};

std::string EntityFactory::_enemyTypes[MAX_ENEMIES] =
{
    "asteroid",
};

AbstractEnemy*    (EntityFactory::*EntityFactory::createFunc[1])(void) = 
{
	&EntityFactory::createRandomEnemy,
};

EntityFactory &	EntityFactory::operator=(EntityFactory const &rhs)
{
	(void)rhs;
    return *this;
}

AbstractEntity*	EntityFactory::createEntity(std::string type)
{
	(void)type;
    return 0;
}

AbstractEnemy*	EntityFactory::createEnemy()
{
	return 0;
}

AbstractEnemy*	EntityFactory::createRandomEnemy()
{
	return 0;
}

Player*     EntityFactory::createPlayer()
{
	Player *player = new Player(this->_blueprints[0]);
    player->setPosition(Vec2(COLS / 2 - player->getBlueprint()->getSizeX(), LINES - player->getBlueprint()->getSizeY()));
    return player;
}