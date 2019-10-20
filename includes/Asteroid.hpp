/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 08:50:17 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/20 17:56:26 by lnicosia         ###   ########.fr       */
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