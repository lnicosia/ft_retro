/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayingScreen.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:45:32 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 19:17:45 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PlayingScreen.hpp"
#include <unistd.h>
#include <ncurses.h>

PlayingScreen::PlayingScreen(void): _score(0), _highscore(nullptr), _time(0), _map(&this->_score)
{
	
}

PlayingScreen::PlayingScreen(int &highscore):  _score(0), _highscore(&highscore), _time(0), _map()
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
	this->_score = rhs._score;
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
	
		if (input == 27)
			game.setPhase(PHASE_PAUSE);
		else
		{
			this->_map.getPlayer().setInput(input);
			this->process(game);
			this->_print(game);
			usleep(10000);
		}
		clear();
		mvprintw(0, 0, "Game playing...");
		refresh();
	}
}