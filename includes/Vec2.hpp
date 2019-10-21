/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec2.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:05:57 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 20:16:55 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_HPP
# define VEC2_HPP

# include <iostream>

class Vec2
{
	public:
		Vec2(void);
		Vec2(float x, float y);
		Vec2(Vec2 const &instance);
		Vec2 &operator=(Vec2 const &rhs);
		Vec2 &operator+(Vec2 const &rhs);
		Vec2 &operator+=(Vec2 const &rhs);
		Vec2 &operator-(Vec2 const &rhs);
		Vec2 &operator*(Vec2 const &rhs);
		Vec2 &operator/(Vec2 const &rhs);
		Vec2 &operator*(float scalar);

		~Vec2(void);

		void norm(void);
		float getNorm(void);
		Vec2	normed(void);
		float getX(void) const ;
		float getY(void) const ;
		void setX(float x);
		void setY(float y);
		static Vec2 randomVect(void);
	private:
		float _x;
		float _y;

};

std::ostream &operator<<(std::ostream &o, Vec2 const &instance);
#endif