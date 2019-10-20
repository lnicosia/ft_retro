/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackgroundEntity.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:21:20 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 16:24:00 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BackgroundEntity.hpp"

BackgroundEntity::BackgroundEntity(void)
{
	
}

BackgroundEntity::BackgroundEntity(Vec2 pos, Vec2 dir, Blueprint *blueprint): AbstractEntity(pos, dir, blueprint)
{
	
}

BackgroundEntity::BackgroundEntity(BackgroundEntity const &instance)
{
	*this = instance;	
}

BackgroundEntity::~BackgroundEntity(void)
{
	
}

BackgroundEntity &	BackgroundEntity::operator=(BackgroundEntity const &rhs)
{
	(void)rhs;
	return *this;
}

void	BackgroundEntity::onCollide(Player &player)
{
	(void)player;
}

void	BackgroundEntity::onCollide(AbstractEnemy &enemy, Map &map)
{
	(void)map;
	(void)enemy;
}


bool	BackgroundEntity::shouldBeCleaned(void)
{
	return false;
}