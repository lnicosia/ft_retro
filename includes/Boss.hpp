/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:25:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 19:52:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_HPP
# define BOSS_HPP

# include <iostream>
# include "AbstractEnemy.hpp"

class Boss : public AbstractEnemy
{
	public:
		Boss(void);
		Boss(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		Boss(Boss const &instance);
		Boss &operator=(Boss const &rhs);
		virtual ~Boss(void);
		virtual int		getColor() const;
		virtual void 	update(Map &map);
	
	private:
		
};
#endif