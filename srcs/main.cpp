/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:15:46 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/19 15:15:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
// #include "Blueprint.hpp"
// #include "Player.hpp"
#include "Game.hpp"
#include <iostream>

int main()
{

	Game game;

	try {
		game.launch();
	}
	catch(std::exception e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

// int     main(int ac, char **av)
// {
//     if (ac != 3)
//         return 0;
// 	AbstractForegroundEntity *player1 = new Player();
// 	AbstractForegroundEntity *player2 = new Player();
//     Blueprint   img1(av[1]);
//     Blueprint   img2(av[2]);
// 	player1->setBlueprint(&img1);
// 	player2->setBlueprint(&img2);
//     int         run = 1, c1 = 0;//, c2 = 0;

//     //std::cout << img1 << std::endl;
//     initscr();
//     cbreak();
//     keypad(stdscr, TRUE);
//     curs_set(0);
//     player1->setPosition(Vec2(COLS / 2, LINES/ 2));
//     player2->setPosition(player1->getPosition() - Vec2(20, 0));
//     //printw("Ncurses mode entered\n");
// 	player1->render();
// 	player2->render();
//     refresh();
//     while (run)
//     {
//         c1 = getch();
//         //c2 = getch();
//         switch(c1)
//         {
//             case 'a':
//             case KEY_LEFT:
// 				player1->setPosition(player1->getPosition() + Vec2(-1, 0));
//                 if (player1->collide(*player2))
//                     player1->setPosition(player1->getPosition() + Vec2(1, 0));
//                 break;
//             case 'd':
//             case KEY_RIGHT:
// 				player1->setPosition(player1->getPosition() + Vec2(1, 0));
//                 if (player1->collide(*player2))
//                     player1->setPosition(player1->getPosition() + Vec2(-1, 0));
//                 break;
//             case 'w':
//             case KEY_UP:
// 				player1->setPosition(player1->getPosition() + Vec2(0, -1));
//                 if (player1->collide(*player2))
//                     player1->setPosition(player1->getPosition() + Vec2(0, 1));
//                 break;
//             case 's':
//             case KEY_DOWN:
//                 player1->setPosition(player1->getPosition() + Vec2(0, 1));
//                 if (player1->collide(*player2))
//                     player1->setPosition(player1->getPosition() + Vec2(0, -1));
//                 break;
//             case 27:
//                 run = 0;
//         }
//         clear();
// 		player1->render();
// 		player2->render();
//         refresh();
//     }
//     endwin();
//     return 0;
// }
