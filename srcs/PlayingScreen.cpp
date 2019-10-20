/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayingScreen.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:45:32 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 18:05:30 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PlayingScreen.hpp"
#include <unistd.h>
#include <ncurses.h>

PlayingScreen::PlayingScreen(void): _highscore(nullptr), _time(0), _map()
{
	
}

PlayingScreen::PlayingScreen(int &highscore): _highscore(&highscore), _time(0), _map()
{
	
}

PlayingScreen::PlayingScreen(PlayingScreen const &instance)
{
	*this = instance;
}

PlayingScreen::~PlayingScreen(void)
{
	
}

PlayingScreen &	PlayingScreen::operator=(PlayingScreen const &rhs)
{
	this->_highscore = rhs._highscore;
	this->_map = rhs._map;
	this->_time = rhs._time;
	return *this;
}

void	PlayingScreen::process(Game &game)
{
	(void)game;
	//factory add randomly Entities;
	this->_map.update();
	this->_map.clean();
}

void	PlayingScreen::_printHud(Game &game) const
{
		(void)game;
}

void	PlayingScreen::_print(Game &game) const
{
	this->_map.render();
	this->_printHud(game);
}

void	PlayingScreen::gameLoop(Game &game)
{
	int input;
	while (game.getPhase() == PHASE_PLAYING_SCREEN && !game.isDone())
	{
		input = getch();

		if (input == 'p')
			game.setPhase(PHASE_PAUSE);
		else
		{
			clear();
			//std::cerr << "trying to print game" << std::endl;
			//mvprintw(0, 0, "Game playing...");
			printGameBorder();
			printScoreBorder();
			printScoreInfo(_map.getPlayerLive(), _map.getPlayerScore(), getHighScore());
			this->_map.getPlayer().setInput(input);
			//std::cerr << "Inputs ok" << std::endl;
			this->process(game);
			//std::cerr << "Game process ok" << std::endl;
			this->_print(game);
			//std::cerr << "Game print ok" << std::endl;
			refresh();
			usleep(15000);
		}
		
	}
}

void	PlayingScreen::printGameBorder()
{
	/*
		line 5 == Start of Game Border
		Line - 1 == End of Game Border
	*/
		/* Print Upper Border && Print Lower Border */
		for (int i = 0; i < COLS - 4; i++)
		{
			mvprintw(5, 2 + i, "-");
			//mvprintw(LINES - 1, 2 + i, "-");
		}
	/* Print Left Border && Print Right Border */ 
		for (int  i = 0; i < LINES - 3; i++)
		{
			mvprintw(6 + i, 2, "|");
			mvprintw(6 + i, COLS - 3, "|"); 
		}
}

void	PlayingScreen::printScoreBorder()
{
	/*
		Note: Lower border is Printed with  printGameBorder
	*/
	/* Print Upper Border */
		for (int i = 0; i < COLS - 4; i++)
			mvprintw(1, 2 + i, "-");
	/* Print Left Border  && Print Right Border */
		for (int  i = 0; i < 5; i++)
		{
			mvprintw(2 + i, 2, "|");
			mvprintw(2 + i, COLS - 3, "|"); 
		}
}

void	PlayingScreen::printScoreInfo(int life, int score, int maxscore)
{
	std::string tmp;
	/* Print Life */
	attrset(COLOR_PAIR(1));
	tmp = std::to_string(life);
	mvprintw(3, 5, "LIFE = ");
	mvprintw(3, 12, tmp.c_str());

	/* Print Game Score */
	attrset(COLOR_PAIR(2));
	tmp = std::to_string(score);
	mvprintw(3, 20, "SCORE = ");
	mvprintw(3, 28, tmp.c_str());

	/* Print Max Score */
	attrset(COLOR_PAIR(3));
	tmp = std::to_string(maxscore);
	mvprintw(3, 40, "MAXSCORE = ");
	mvprintw(3, 52, tmp.c_str());
	attrset(COLOR_PAIR(0));
}

int			PlayingScreen::getHighScore()
{
	return (*_highscore);
}