/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:41:28 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 18:41:29 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_HPP
# define ASTEROID_HPP

#include "AbstractEnemy.hpp"

class Asteroid: public AbstractEnemy
{
    public:
        Asteroid(void);
		//Asteroid(** replace parameters **);
        Asteroid(Vec2 pos, Vec2 dir, Blueprint *blueprint);
        // Asteroid(Vec2 pos, Vec2 dir, Blueprint *blueprint, int health, int scoreOnDeath, WeaponSlot ws);
		Asteroid(Asteroid const &instance);
		Asteroid &operator=(Asteroid const &rhs);
		~Asteroid(void);

        virtual int		getColor() const;
		//Override la fonction si on veut donner un comportement particulier a l'Asteroid
        //virtual void    update(Map &map);
		//virtual bool    shouldBeCleaned();


        // virtual void    onCollide(Player &player);
        // virtual void    onCollide(AbstractEnemy &enemy, Map &map);
    private:
};

#endif