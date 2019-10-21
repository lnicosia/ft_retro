/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star3.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:17:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:21:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR3_HPP
# define STAR3_HPP

# include <iostream>
# include "BackgroundEntity.hpp"

class Star3 : public  BackgroundEntity
{
	public:
		Star3(void);
		Star3(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		Star3(Star3 const &instance);
		Star3 &operator=(Star3 const &rhs);
		virtual ~Star3(void);

		virtual int getColor(void) const;
	private:

};

#endif