/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityFactory.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:25:42 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/19 21:08:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYFACTORY_HPP
# define ENTITYFACTORY_HPP

#define MAX_BLUEPRINT 5
#define MAX_ENEMIES 1

#include "AbstractEnemy.hpp"
#include "Alien.hpp"

class EntityFactory
{
	public:
		EntityFactory(void);
		EntityFactory(EntityFactory const &instance);
		EntityFactory &operator=(EntityFactory const &rhs);
		~EntityFactory(void);
        AbstractEntity*         createEntity(std::string type);
        AbstractEnemy*          createEnemy();
        AbstractEnemy*          createRandomEnemy();
        Player*                 createPlayer();
        AbstractEnemy*          createAlien();
        
	private:
        static Blueprint*       _blueprints[MAX_BLUEPRINT];
        static std::string      _blueprintsId[MAX_BLUEPRINT];
        static std::string      _enemyTypes[MAX_ENEMIES];
        static AbstractEnemy*  (EntityFactory::*_createFunc[1])(void);

};

#endif