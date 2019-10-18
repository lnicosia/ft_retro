/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractForegroundEntity.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:37:47 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 17:46:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractForegroundEntity.hpp"

AbstractForegroundEntity::AbstractForegroundEntity(void)
{
	
}

AbstractForegroundEntity::AbstractForegroundEntity(Vec2 pos, Vec2 dir, Blueprint blueprint): AbstractEntity(pos, dir, blueprint)
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

bool	AbstractForegroundEntity::collide(const AbstractEntity &entity)
{
	(void)entity;
	return true;
}