/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:47:15 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 22:03:56 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Vec2.hpp"

Vec2::Vec2(void): _x(0), _y(0)
{
	
}

Vec2::Vec2(int x, int y): _x(x), _y(y)
{
	
}

Vec2::Vec2(Vec2 const &instance)
{
	*this = instance;
}

Vec2 &Vec2::operator=(Vec2 const &rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	return *this;
}

Vec2 &Vec2::operator+(Vec2 const &rhs)
{
	Vec2 res(this->_x + rhs._x, this->_y + rhs._y);

	*this = res;
	return *this;
}

Vec2 &Vec2::operator-(Vec2 const &rhs)
{
	Vec2 res(this->_x - rhs._x, this->_y - rhs._y);

	*this = res;
	return *this;
}

Vec2 &Vec2::operator/(Vec2 const &rhs)
{
	Vec2 res(this->_x / rhs._x, this->_y / rhs._y);

	*this = res;
	return *this;
}

Vec2 &Vec2::operator*(Vec2 const &rhs)
{
	Vec2 res(this->_x * rhs._x, this->_y * rhs._y);

	*this = res;
	return *this;
}

Vec2 &Vec2::operator+=(Vec2 const &rhs)
{
	this->_x += rhs._x;
	this->_y += rhs._y;
	return *this;
}

Vec2::~Vec2(void)
{
	
}

int	Vec2::getX(void) const
{
	return (this->_x);
}

int	Vec2::getY(void) const
{
	return (this->_y);
}

void	Vec2::setX(int x)
{
	this->_x = x;
}

void	Vec2::setY(int y)
{
	this->_y = y;
}

std::ostream &	operator<<(std::ostream &o, Vec2 const &instance)
{
	o << instance.getX() << " ; " << instance.getY();
	return o;
}