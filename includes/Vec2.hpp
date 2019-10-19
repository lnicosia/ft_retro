/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec2.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:05:57 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 22:02:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_HPP
# define VEC2_HPP

# include <iostream>

class Vec2
{
	public:
		Vec2(void);
		Vec2(int x, int y);
		Vec2(Vec2 const &instance);
		Vec2 &operator=(Vec2 const &rhs);
		Vec2 &operator+(Vec2 const &rhs);
		Vec2 &operator+=(Vec2 const &rhs);
		Vec2 &operator-(Vec2 const &rhs);
		Vec2 &operator*(Vec2 const &rhs);
		Vec2 &operator/(Vec2 const &rhs);
		~Vec2(void);

		int getX(void) const ;
		int getY(void) const ;
		void setX(int x);
		void setY(int y);

	private:
		int _x;
		int _y;

};

std::ostream &operator<<(std::ostream &o, Vec2 const &instance);
#endif