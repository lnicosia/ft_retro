/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:15:46 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/18 17:14:01 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Game.hpp"

int main()
{
	Game game;

	try
	{
		game.launch();
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}