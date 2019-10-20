/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractForegroundEntity.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:37:47 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 17:58:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractForegroundEntity.hpp"
#include <ncurses.h>

AbstractForegroundEntity::AbstractForegroundEntity(void)
{
	
}

AbstractForegroundEntity::AbstractForegroundEntity(Vec2 pos, Vec2 dir, Blueprint *blueprint): AbstractEntity(pos, dir, blueprint)
{
	
}

AbstractForegroundEntity::AbstractForegroundEntity(AbstractForegroundEntity const &instance)
{
	*this = instance;
}

AbstractForegroundEntity::~AbstractForegroundEntity(void)
{
	
}

AbstractForegroundEntity &	AbstractForegroundEntity::operator=(AbstractForegroundEntity const &rhs)
{
	(void)rhs;
	//TODO
	return *this;
}

int		AbstractForegroundEntity::getColor() const
{
	return COLOR_WHITE;
}