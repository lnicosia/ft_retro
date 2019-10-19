/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstracEnemyProjectile.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 08:51:27 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 14:45:08 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACENEMYPROJECTILE_HPP
# define ABSTRACENEMYPROJECTILE_HPP

# include <iostream>
# include "Vec2.hpp"
# include "Blueprint.hpp"

class AbstracEnemyProjectile
{
	public:
		AbstracEnemyProjectile(void);
		AbstracEnemyProjectile(Vec2 pos, Vec2 dir, Blueprint blueprint, int damage);
		AbstracEnemyProjectile(AbstracEnemyProjectile const &instance);
		AbstracEnemyProjectile &operator=(AbstracEnemyProjectile const &rhs);
		virtual ~AbstracEnemyProjectile(void);

	private:

};

std::ostream &operator<<(std::ostream &o, AbstracEnemyProjectile const &instance);
#endif