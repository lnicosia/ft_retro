/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayingScreen.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:06:21 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 00:57:08 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYINGSCREEN_HPP
# define PLAYINGSCREEN_HPP

# include <iostream>
# include "Map.hpp"
# include "Game.hpp"

class Game;

class PlayingScreen
{
	public:
		PlayingScreen(int &highscore);
		PlayingScreen(PlayingScreen const &instance);
		PlayingScreen &operator=(PlayingScreen const &rhs);
		~PlayingScreen(void);
		void		gameLoop(Game &game);
		void		_printHud(Game &game) const;
		void		_print(Game &game) const;
		

	private:
		PlayingScreen(void);
		void	process(Game &game);

		int		*_highscore;
		time_t	_time;
		Map		_map;
};
#endif