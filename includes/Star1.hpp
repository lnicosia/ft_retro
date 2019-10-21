/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star1.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:17:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:18:48 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR1_HPP
# define STAR1_HPP

# include <iostream>
# include "BackgroundEntity.hpp"

	
class Star1 : public  BackgroundEntity
{
	public:
		Star1(void);
		Star1(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		Star1(Star1 const &instance);
		Star1 &operator=(Star1 const &rhs);
		virtual ~Star1(void);

		virtual int getColor(void) const;
	private:

};

#endif