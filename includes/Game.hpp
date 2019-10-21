/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:39:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 19:14:45 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include "PlayingScreen.hpp"
# include <ncurses.h>
# define PHASE_MENU 0
# define PHASE_PLAYING_SCREEN 1
# define PHASE_PAUSE 2
# define RED 1
# define GREEN 2
# define YELLOW 3
# define BLUE 4
# define CYAN 5
# define MAGENTA 6
# define WHITE 7

class PlayingScreen;

class Game
{
	public:
		Game(void);
		Game(Game const &instance);
		Game & operator=(Game const &rhs);
		~Game();

		void launch();

		void	loopPlayingScreen(void);
		void	loopMenuScreen(void);
		void	loopPauseScreen(void);
	
		void	setDone(bool done);
		bool	isDone(void);
		void	setPhase(int phase);
		int		getPhase(void);
		int		getHighscore(void);
		void	setHighscore(int highscore);

		/* Functions to Print menus loop */
		void	printMenus();
		void	printMenusBorder();
		void	printMenusText();
		int		printMenusCursor(int x, int y);

	private:
		PlayingScreen	*_playingScreen;
		int				_phase;
		int				_highscore;
		bool			_done;
		static void (Game::*loopArray[3])(void);
		
};
#endif
