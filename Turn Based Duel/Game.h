#pragma once
#include "Player.h"
class Game
{
private:
	Player g_player1;
	Player g_player2;
	Player* g_currentPlayer;

public:
	Game(Player p1, Player p2) : g_player1(p1), g_player2(p2)
	{
		g_currentPlayer = &g_player1;
	}

	void G_Winner()
	{
		if (g_player1.P_IsAlive())
		{
			std::cout << "Player 1 Wins";
		}
		else if (g_player2.P_IsAlive())
		{
			std::cout << "Player 2 Wins";
		}
	}

	void G_Play()
	{
		std::cout << "Welcome to player vs player \n";

		//repeat both turns ack to back as long as both players are alive
		while (g_player1.P_IsAlive() && g_player2.P_IsAlive())
		{
			std::cout << "Take turns to see who wins \n";
			std::cout << "Player 1 attack \n";
			if (g_currentPlayer == &g_player1)
			{
				g_player1.P_Attack(g_player2);
				g_player2.P_PrintStats();
				g_currentPlayer = &g_player2;
			}
			std::cout << "\n";
			std::cout << "Player 2 attack \n";
			if (g_currentPlayer == &g_player2)
			{
				g_player2.P_Attack(g_player1);
				g_player1.P_PrintStats();
				g_currentPlayer = &g_player1;
			}
			std::cout << "please press enter to go to the next round \n";
			std::cin.get();
		}
		return G_Winner();
	}
};