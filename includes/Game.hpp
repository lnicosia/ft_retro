/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:39:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 15:42:41 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include "PlayingScreen.hpp"

#define PHASE_PLAYING_SCREEN 0;
#define PHASE_MENU 1;
#define PHASE_PAUSE 2;

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

	private:
		PlayingScreen	*_playingScreen;
		int				_phase;
		bool			_done;
	
		static void (Game::*loopArray[3])(void);
		
};
#endif
