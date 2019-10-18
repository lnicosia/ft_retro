/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:00:22 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 21:01:07 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"
#include <ncurses.h>

Player::Player(void) : AbstractForegroundEntity(Vec2(0, 0), Vec2(0, 0), Blueprint()), _input(ERR)
{
	int i;

	i = 0;
	while (i < 2)
	{
		this->_weapons[i] = nullptr;
		i++;
	}	
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
	this->_boost = rhs._boost;
	return *this;
}

void	Player::process(void)
{
	
}

AbstractWeapon	*Player::getWeapon(int i)
{
	return (this->_weapons[i]);
}

int	Player::getBoost(void)
{
	return (this->_boost);
}

void	Player::setBoost(int boost)
{
	this->_boost = boost;
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