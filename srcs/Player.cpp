/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:00:22 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 16:24:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"
#include <ncurses.h>

Player::Player(void) : AbstractForegroundEntity(Vec2(0, 0), Vec2(0, 0), Blueprint("player.ascii")), _input(ERR)
{
	// int i;

	// i = 0;
	// while (i < 2)
	// {
	// 	this->_weaponSlots[i].setWeapon = nullptr;
	// 	i++;
	// }	
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
	return true;
}

void		Player::update(Map &map)
{
	(void)map;
}