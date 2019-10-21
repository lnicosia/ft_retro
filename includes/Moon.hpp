/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:20:09 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 19:38:45 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOON_HPP
# define MOON_HPP

# include <iostream>
# include "BackgroundEntity.hpp"

	
class Moon : public  BackgroundEntity
{
	public:
		Moon(void);
		Moon(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		Moon(Moon const &instance);
		Moon &operator=(Moon const &rhs);
		virtual ~Moon(void);

		virtual int getColor(void) const;
	private:

};

#endif