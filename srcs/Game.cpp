/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:18:10 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 20:45:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Game.hpp"
#include <ncurses.h>
#include <unistd.h>

double	currentTime;

Game::Game(void): _playingScreen(nullptr), _phase(PHASE_MENU), _highscore(0), _done(false)
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
	int input = 0;
	int i = 0;
	while (!this->_done)
	{	
		printMenus();
		refresh();
		input = getch();
		if (input == 10)
		{
			//START GAME
		}
	}
	//loop (waiting for player to select PLAY)
	this->_playingScreen = new PlayingScreen(this->_highscore);
	this->_phase = PHASE_PLAYING_SCREEN;
}

void	Game::loopPauseScreen(void)
{
	int	input = 0;
	//loop (waiting for player to select RESUME OR QUIT)
	//delete this->_playingScreen;
	while (this->_phase == PHASE_PAUSE && !this->_done)
	{
		input = getch();
	
		clear();
		mvprintw(0, 0, "Pres ESC to quit, 'P' to resume game");
		refresh();
		if (input == 27)
			this->_done = 1;
		else if (input == 'p')
			this->_phase = PHASE_PLAYING_SCREEN;
		else
		{
			usleep(10000);
		}
	}
}

void	Game::launch()
{
	//init (get highscore ...)

	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	noecho();
	while (!this->_done)
	{
		(this->*Game::loopArray[this->_phase])();
		currentTime = clock() / CLOCKS_PER_SEC;
	}
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
/* --------------------------------- Functions to Print menus loop --------------------------- */

void	Game::printMenus()
{
	printMenusBorder();
	printMenusText();
}

void	Game::printMenusBorder()
{
	int i = 0;
	if (LINES/2-5 > 0 && COLS / 2 - 5)
	{
		mvprintw(LINES / 2 - 5, COLS / 2, "--------------------------------------------------");
		mvprintw(LINES / 2 + 5, COLS / 2, "--------------------------------------------------");
		while (i < 5)
		{
			mvprintw(LINES / 2 + i, COLS / 2, "|");
			mvprintw(LINES / 2 - i, COLS / 2, "|");
			mvprintw(LINES / 2 - i, COLS / 2 + 49, "|");
			mvprintw(LINES / 2 + i, COLS / 2 + 49, "|");
			i++;
		}
	}
}

void	Game::printMenusText()
{
	mvprintw(LINES / 2 , COLS / 2 + 1, "Welcome, Press ESC to quit, Press ENTER to play");
}