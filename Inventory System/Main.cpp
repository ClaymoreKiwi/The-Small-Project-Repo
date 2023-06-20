/*
project goals
	- Be able to add items
	- able to remove items
	- show inventory
	- sort inventory
	- find specific items
*/
#include "Player.h"
#include <iostream>

int main()
{
	P_Player myPlayer;
	int myNewItemVal = 0;
	std::string myNewItemName = "empty";
	char userSelection = ' ';
	std::cout << "Welcome player\n";
	std::cout << "Choose a menu option\n";

	while (userSelection != 0)
	{
		std::cout << "1: Add items\n";
		std::cout << "2: Remove items\n";
		std::cout << "3: Show inventory\n";
		std::cout << "4: Sort inventory\n";
		std::cout << "5: Find item\n";
		std::cout << "0: EXIT\n";
		std::cin >> userSelection;

		switch (userSelection)
		{
		case'1':
		{
			std::cout << "Enter the value of this item in numbers: ";
			std::cin >> myNewItemVal;
			std::cout << "Enter the name of your item: ";
			std::cin >> myNewItemName;
			I_Item myNewItem(myNewItemVal, myNewItemName);
			myPlayer.PAddToInventory(myNewItem);
			std::cout << "Item added \n\n";
			std::cin.get();
			break;
		}
		case'2':
			std::cout << "Enter the name of the item you want removed: ";
			std::cin >> myNewItemVal;
			myPlayer.PRemoveFromInventory(myNewItemName);
			std::cout << "Item removed";
			std::cin.get();
			break;
		case'3':
			myPlayer.PGetInventory();
			std::cin.get();
			break;
		case'4':
			myPlayer.PsortInventory();
			break;
		case'5':
			std::cout << "Enter the name of the item you want to view: ";
			std::cin >> myNewItemVal;
			myPlayer.PFindItem(myNewItemName);
			std::cin.get();
			break;
		case'0':
			return 0;
		default:
			std::cout << "invalid option\n";
		}

	}
	std::cin.get();
}