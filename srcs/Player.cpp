/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:00:22 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 17:14:11 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"

Player::Player(void) : AbstractEntity()
{
	int i;

	i = 0;
	while (i < 2)
	{
		this->_weapons[i] = nullptr;
		i++;
	}	
}

Player::Player(Player const &instance)
{
	
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

std::ostream &	operator<<(std::ostream &o, Player const &instance)
{
	
}