/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:47:15 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 20:47:19 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Vec2.hpp"
#include <math.h>

Vec2::Vec2(void): _x(0), _y(0)
{
	
}

Vec2::Vec2(float x, float y): _x(x), _y(y)
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


Vec2 &Vec2::operator*(float scalar)
{
	this->_x *= scalar;
	this->_y *= scalar;
	return *this;
}


Vec2::~Vec2(void)
{
	
}

float 	Vec2::getNorm(void)
{
	return sqrt(this->_x * this->_x + this->_y * this->_y);
}

Vec2 Vec2::normed(void)
{
	Vec2 res(*this);

	res.norm();
	return (res);
}

void Vec2::norm(void)
{
	float norm;

	norm = this->getNorm();
	if (norm != 0)
	{
		this->_x /= norm;
		this->_y /= norm;
	}
}

float	Vec2::getX(void) const
{
	return (this->_x);
}

float	Vec2::getY(void) const
{
	return (this->_y);
}

void	Vec2::setX(float x)
{
	this->_x = x;
}

void	Vec2::setY(float y)
{
	this->_y = y;
}

std::ostream &	operator<<(std::ostream &o, Vec2 const &instance)
{
	o << instance.getX() << " ; " << instance.getY();
	return o;
}

Vec2	Vec2::randomVect(void)
{
	Vec2 res;

	double val = double(rand()) / (double(RAND_MAX));
	val  = val * M_PI * 2;
	res.setX(sin(val));
	res.setY(cos(val));
	return res;
}