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
#include <string>

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
	int c_lines = (LINES / 2) +1; // (LINES / 2) + x, x = number of options, 1 being the first one;
	int c_cols  = (COLS / 2) - 27;
	std::string tmp;
	while (this->_phase == PHASE_MENU && !this->_done)
	{
		clear();
		printMenus();
		printMenusCursor(c_lines, c_cols);
		refresh();
		input = getch();
		tmp = std::to_string(input);
		mvprintw(0,50,tmp.c_str());
		if (input == 10)
		{
			if (c_lines == (LINES / 2) +1)
				this->_done = true;
			if (c_lines == (LINES / 2) +2)
			{
				this->_playingScreen = new PlayingScreen(this->_highscore);
				this->_phase = PHASE_PLAYING_SCREEN;
			}
		}
		if (input == KEY_DOWN)
		{
			c_lines++;
			if (c_lines > (LINES / 2) +2)
				c_lines = (LINES / 2) +1;
		}
		if (input == KEY_UP)
		{
			c_lines--;
			if (c_lines < (LINES / 2) +1)
				c_lines = (LINES / 2) +2;
		}
		
	}
	//loop (waiting for player to select PLAY)
	//this->_playingScreen = new PlayingScreen(this->_highscore);
	//this->_phase = PHASE_PLAYING_SCREEN;
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
		mvprintw(0, 0, "Press ESC to quit, 'P' to resume game");
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
	std::string lines = std::to_string(LINES);
	std::string cols = std::to_string(COLS);
	int i;
	if (LINES > 10 && COLS > 10) // Random value
	{
		mvprintw(0 , 0, lines.c_str());
		mvprintw(0 , 5, cols.c_str());

	/* Print Upper Border */
		for (unsigned int i = 0; i < COLS - 4; i++)
			mvprintw(1, 2 + i, "-");
	/* Print Lower Border */
		for (unsigned int  i = 0; i < COLS - 4; i++)
			mvprintw(LINES - 1, 2 + i, "-");
	/* Print Left Border */
		for (unsigned int  i = 0; i < LINES - 3; i++)
			mvprintw(2 + i, 2, "|");
	/* Print Right Border */
		for (unsigned int  i = 0; i < LINES - 3; i++)
			mvprintw(2 + i, COLS - 3, "|");
	}
}

void	Game::printMenusText()
{
	/* Print Game Title */
	int Cols = (COLS / 2) - 26; // 26 = lenght of text(52) / 2;
	int Lines = (LINES / 2) / 2;

	mvprintw(Lines, Cols, " _____  ____       _____  _____  ____  _____  _____ ");
	mvprintw(Lines + 1, Cols, "/   __\\/    \\ ___ /  _  \\/   __\\/    \\/  _  \\/  _  \\");
	mvprintw(Lines + 2, Cols, "|   __|\\-  -/<___>|  _  <|   __|\\-  -/|  _  <|  |  |");
	mvprintw(Lines + 3, Cols, "\\__/    |__|      \\__|\\_/\\_____/ |__| \\__|\\_/\\_____/");

	/* Print Actions Message */
	mvprintw(LINES / 2 , (COLS / 2) - 23, "Welcome, Press ESC to quit, Press Enter to play");
	mvprintw(LINES / 2 +1, (COLS / 2) - 23, "quit");
	mvprintw(LINES / 2 +2, (COLS / 2) - 23, "play");

}

int		Game::printMenusCursor(int x, int y)
{

	mvprintw(x, y, "-->");
		
	return (-1);
}