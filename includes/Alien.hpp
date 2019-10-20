/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alien.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:34:27 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 09:56:42 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIEN_HPP
# define ALIEN_HPP

#include "AbstractEnemy.hpp"

class Alien : public AbstractEnemy
{
	public:
		Alien(void);
        Alien(Vec2 pos, Vec2 dir, Blueprint *blueprint);
		Alien(Alien const &instance);
		Alien &operator=(Alien const &rhs);
		~Alien(void);

		//Override la fonction si on veut donner un comportement particulier a l'alien
        // virtual void    update(Map &map);
		//virtual bool    shouldBeCleaned();


        // virtual void    onCollide(Player &player);
        // virtual void    onCollide(AbstractEnemy &enemy, Map &map);
	private:

};

#endif