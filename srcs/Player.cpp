/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:00:22 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 17:54:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"
#include "../includes/AbstractEnemy.hpp"
#include <ncurses.h>
#include "Map.hpp"
#include "LaserThrower.hpp"


Player::Player(void):
	AbstractForegroundEntity(Vec2(0, 0), Vec2(0, 0), nullptr), _lives(5), _score(0), _input(ERR), _acceleration(0.3)
{
	this->_init();
}


Player::Player(Vec2 pos, Vec2 dir,Blueprint *blueprint):
	AbstractForegroundEntity(pos, dir, blueprint), _lives(5), _score(0), _input(ERR), _acceleration(0.3)
{
	this->_init();
}


Player::Player(Blueprint *blueprint):
	AbstractForegroundEntity(Vec2(0, 0), Vec2(0, 0), blueprint), _lives(5), _score(0), _input(ERR), _acceleration(0.3)
{
	this->_init();
}

//TODO
Player::Player(Player const &instance)
{
	*this = instance;
}

Player::~Player(void)
{
	
}

Player &	Player::operator=(Player const &rhs)
{
	//TODO
	(void)rhs;
	return *this;
}

void	Player::process(void)
{
	
}

void	Player::looseLife()
{
	this->_lives--;
}

void	Player::gainLife()
{
	this->_lives++;
}

void	Player::incScore(int scoreToAdd)
{
	this->_score += scoreToAdd;
}

std::ostream &	operator<<(std::ostream &o, Player const &instance)
{
	(void)instance;
	return o;
}

int	Player::getInput(void)
{
	return (this->_input);
}

void	Player::setInput(int input)
{
	this->_input = input;
}

void	Player::shoot(Map &map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (this->_weaponSlots[i] && this->_weaponSlots[i]->getWeapon())
		{
			this->_weaponSlots[i]->getWeapon()->beShot(*this, *(this->_weaponSlots[i]), map);
		}
		i++;
	}
}

WeaponSlot*	Player::getWeaponSlot(int i)
{
	return (this->_weaponSlots[i]);
}

bool		Player::shouldBeCleaned()
{
	return false;
}

void		Player::update(Map &map)
{
	(void)map;
	switch (this->_input)
	{
		case 'a':
		case KEY_LEFT:
			this->setDirection(this->getDirection() - Vec2(this->_acceleration, 0));
			break;
		case 'd':
		case KEY_RIGHT:
			this->setDirection(this->getDirection() + Vec2(this->_acceleration, 0));
			break;
		case 'w':
		case KEY_UP:
			this->setDirection(this->getDirection() - Vec2(0, this->_acceleration));
			break;
		case 's':
		case KEY_DOWN:
			this->setDirection(this->getDirection() + Vec2(0, this->_acceleration));
			break;
		case ' ':
			this->shoot(map);
			break;
		/*case 'a':
		case KEY_LEFT:
			this->setPosition(this->getPosition() + Vec2(-1, 0));
			break;
		case 'd':
		case KEY_RIGHT:
			this->setPosition(this->getPosition() + Vec2(1, 0));
			break;
		case 'w':
		case KEY_UP:
			this->setPosition(this->getPosition() + Vec2(0, -1));
			break;
		case 's':
		case KEY_DOWN:
				this->setPosition(this->getPosition() + Vec2(0, 1));
			break;
		case ' ':
			this->shoot(map);
			break;*/
	}
	//(void)this->_acceleration;
	if (this->getDirection().getNorm() > 1.2)
	{
		this->setDirection(this->getDirection().normed() * 1.2);
	}
	else if (this->getDirection().getNorm() < 0.1)
		this->setDirection(Vec2(0,0));
	this->setDirection(this->getDirection() * 0.95);
	Vec2 newPos = this->getPosition() + this->getDirection();

	this->setDirection(this->getDirection());
	//std::cerr << this->getDirection() << std::endl;
	this->AbstractEntity::update(map);

	if (this->getPosition().getX() + this->getBlueprint()->getSizeX() > COLS)
	{
		this->setDirection(Vec2(0, this->getDirection().getY()));
		this->setPosition(Vec2(COLS - this->getBlueprint()->getSizeX() - 1, this->getPosition().getY()));
	}
	else if (this->getPosition().getX() < 0)
	{
		this->setDirection(Vec2(0, this->getDirection().getY()));
		this->setPosition(Vec2(0, this->getPosition().getY()));
	}
	if (this->getPosition().getY() + this->getBlueprint()->getSizeY() > LINES)
	{
		this->setDirection(Vec2(this->getDirection().getX(), 0));
		this->setPosition(Vec2(this->getPosition().getX(), LINES - this->getBlueprint()->getSizeY() - 1));
	}
	else if (this->getPosition().getY() < 0)
	{
		this->setDirection(Vec2(this->getDirection().getX(), 0));
		this->setPosition(Vec2(this->getPosition().getX(), 0));
	}
	int i;

	i = 0;
	while (i < map.getEnemies().getSize())
	{
		//std::cerr << "Checking collisions with enemy " << i << std::endl;
		if (this->collide(*(AbstractForegroundEntity *)(map.getEnemies().getEntity(i))))
		{
			//std::cerr << "Collision with enemy " << i << std::endl;
			this->onCollide(*(AbstractEnemy *)map.getEnemies().getEntity(i), map);
		}
		i++;
	}
	i = 0;
	while (i < map.getPickups().getSize())
	{
		if (this->collide(*(AbstractPickup *)(map.getPickups().getEntity(i))))
		{
			((AbstractPickup *)map.getPickups().getEntity(i))->onCollide(*this);
		}
		i++;
	}
	i = 0;
	while (i < map.getPickups().getSize())
	{
		if (this->collide(*(AbstractPickup *)(map.getPickups().getEntity(i))))
		{
			((AbstractPickup *)map.getPickups().getEntity(i))->onCollide(*this);
		}
		i++;
	}
	i = 0;
	while (i < map.getEnemiesProjectiles().getSize())
	{
		if (this->collide(*(AbstractProjectile *)(map.getEnemiesProjectiles().getEntity(i))))
		{
			((AbstractProjectile *)map.getEnemiesProjectiles().getEntity(i))->onCollide(*this);
		}
		i++;
	}
}

void	Player::onCollide(Player &player)
{
	(void)player;
}

void	Player::onCollide(AbstractEnemy &enemy, Map &map)
{
	enemy.takeDamage(200, map);
	this->setDirection(this->getDirection() * 0.6);
	this->_lives--;
}

void		Player::_init(void)
{
	int i;

	i = 0;
	while (i < 4)
	{
		this->_weaponSlots[i] = nullptr;
		i++;
	}
	this->_weaponSlots[0] = new WeaponSlot(Vec2(3, 0), Vec2(0, -1), new LaserThrower());
	// this->_weaponSlots[1] = new WeaponSlot(Vec2(-1 , 3), Vec2(-1, -1), new LaserThrower());
	// this->_weaponSlots[2] = new WeaponSlot(Vec2(6, 3), Vec2(1, -1), new LaserThrower());
}

int		Player::getLives()
{
	return (_lives);
}

int		Player::getScore()
{
	return (_score);
}

int		Player::getColor() const
{
	return COLOR_WHITE;
}
