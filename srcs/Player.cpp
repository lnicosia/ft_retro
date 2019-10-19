/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:00:22 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 22:14:04 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"
#include "../includes/AbstractEnemy.hpp"
#include <ncurses.h>

Player::Player(void):
	AbstractForegroundEntity(Vec2(0, 0), Vec2(0, 0), nullptr), _lives(nullptr), _input(ERR)
{
	// int i;

	// i = 0;
	// while (i < 2)
	// {
	// 	this->_weaponSlots[i].setWeapon = nullptr;
	// 	i++;
	// }	
}

Player::Player(Blueprint *blueprint):
	AbstractForegroundEntity(Vec2(0, 0), Vec2(0, 0), blueprint), _lives(nullptr), _input(ERR)
{
	
}

Player::Player(int *lives):
	AbstractForegroundEntity(Vec2(0, 0), Vec2(0, 0), nullptr), _lives(lives), _input(ERR)
{
	
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
	(*this->_lives)--;
}

//TODO

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
		if (this->_weaponSlots[i].getWeapon())
			this->_weaponSlots[i].getWeapon()->beShot(*this, this->_weaponSlots[i], map);
		i++;
	}
}

WeaponSlot	Player::getWeaponSlot(int i)
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
	switch(this->_input)
	{
		case 'a':
		case KEY_LEFT:
			if (this->getPosition().getX() > 0)
				this->setPosition(this->getPosition() + Vec2(-1, 0));
			break;
		case 'd':
		case KEY_RIGHT:
			if (this->getPosition().getX() + (int)this->getBlueprint()->getSizeX() < COLS)
				this->setPosition(this->getPosition() + Vec2(1, 0));
			break;
		case 'w':
		case KEY_UP:
			if (this->getPosition().getY() > 0)
				this->setPosition(this->getPosition() + Vec2(0, -1));
			break;
		case 's':
		case KEY_DOWN:
			if (this->getPosition().getY() + (int)this->getBlueprint()->getSizeY() < LINES)
				this->setPosition(this->getPosition() + Vec2(0, 1));
			break;

	}
}

void	Player::onCollide(Player &player)
{
	(void)player;
}

void	Player::onCollide(AbstractEnemy &enemy)
{
	enemy.takeDamage(100);
	this->_lives--;
}