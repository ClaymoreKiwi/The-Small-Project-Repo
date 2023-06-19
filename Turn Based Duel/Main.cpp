#include "Game.h"

int main()
{
	char playerInput = 'y';
	std::cout << "welcome to simple class player v player game: \n";
	Player player1(100, 20, 5, "Player 1");
	Player player2(50, 10, 5, "Player 2");

	//print the starting point for the players
	player1.P_PrintStats();
	std::cout << std::endl;
	player2.P_PrintStats();

	//create a new game with the built players
	Game Game(player1, player2);
	Game.G_Play();

	return 0;
}
