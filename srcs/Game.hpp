/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:39:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/17 22:39:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>

class Game
{
	public:
		Game(void);
		Game(Game const &instance);
		Game & operator=(Game const &rhs);
		~Game();
	private:
		
};

std::ostream & operator<<(std::ostream &o, Game const &instance);
#endif
