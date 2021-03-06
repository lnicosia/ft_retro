/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:15:46 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/20 22:45:55 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <iostream>
#include <time.h>

int main(void)
{
	srand(time(nullptr)); 
	Game game;
	try {
		game.launch();
	}
	catch(std::exception e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
