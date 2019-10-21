/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:17:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 21:21:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR2_HPP
# define STAR2_HPP

# include <iostream>
# include "BackgroundEntity.hpp"

	
class Star2 : public  BackgroundEntity
{
	public:
		Star2(void);
		Star2(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		Star2(Star2 const &instance);
		Star2 &operator=(Star2 const &rhs);
		virtual ~Star2(void);

		virtual int getColor(void) const;
	private:

};

#endif