/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractPickup.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:59:52 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 18:59:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractPickup.hpp"

AbstractPickup::AbstractPickup(void)
{
	
}

AbstractPickup::AbstractPickup(Vec2 pos, Vec2 dir, Blueprint *blueprint):
	AbstractForegroundEntity(pos, dir, blueprint)
{
	
}

AbstractPickup::AbstractPickup(AbstractPickup const &instance)
{
	*this = instance;
}

AbstractPickup::~AbstractPickup(void)
{
	
}

AbstractPickup &	AbstractPickup::operator=(AbstractPickup const &rhs)
{
	(void)rhs;
	return *this;
}