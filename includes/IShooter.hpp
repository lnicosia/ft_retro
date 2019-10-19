/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IShooter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:55:08 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 16:11:03 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISHOOTER_HPP
# define ISHOOTER_HPP

class Map;

class IShooter
{
	public:
		virtual void shoot(Map &map) = 0;
};
#endif