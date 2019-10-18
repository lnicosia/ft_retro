/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:18:10 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 20:35:18 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Game.hpp"
#include <ncurses.h>

Game::Game(void): _playingScreen(nullptr), _phase(0), _highscore(0), _done(false)
{
	
}

Game::Game(Game const &instance)
{
	*this = instance;
}

Game::~Game()
{
	
}

Game &	Game::operator=(Game const &rhs)
{
	this->_playingScreen = rhs._playingScreen;
	this->_phase = rhs._phase;
	this->_done = rhs._done;
	return *this;
}

void	Game::loopPlayingScreen(void)
{
	this->_playingScreen->gameLoop(*this);
}

void	Game::loopMenuScreen(void)
{
	//loop (waiting for player to select PLAY)
	this->_playingScreen = new PlayingScreen(this->_highscore);
	this->_phase = PHASE_PLAYING_SCREEN;
}

void	Game::loopPauseScreen(void)
{
	//loop (waiting for player to select RESUME OR QUIT)
	delete this->_playingScreen;
	this->_phase = PHASE_MENU;
}

void	Game::launch()
{
	//init (get highscore ...)

	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	while (!this->_done)
		(this->*Game::loopArray[this->_phase])();
	endwin();
}

void	Game::setDone(bool done)
{
	this->_done = done;
}

bool	Game::isDone(void)
{
	return this->_done;
}

void	Game::setPhase(int phase)
{
	this->_phase = phase;
}

int	Game::getPhase(void)
{
	return (this->_phase);
}

void (Game::*Game::loopArray[3])(void) =
{
	&Game::loopMenuScreen,
	&Game::loopPlayingScreen,
	&Game::loopPauseScreen
};

int		Game::getHighscore()
{
	return (this->_highscore);
}

void	Game::setHighscore(int highscore)
{
	this->_highscore = highscore;
}