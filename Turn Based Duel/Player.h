#pragma once
#include <string>
#include <iostream>

class Player
{
private:
	int p_health = 100;
	int p_strength = 10;
	int p_defence = 10;
	std::string p_name;

public:
	//Default constructor
	Player() {};
	//constructor sets all stats of the player with given values
	Player(int h, int s, int d, std::string name)
	{
		p_health = h;
		p_strength = s;
		p_defence = d;
		p_name = name;
	};
	//allows the player to attack 
	void P_Attack(Player& target)
	{
		target.p_health -= (this->p_strength - target.p_defence);
		if (target.p_health <= 0)
		{
			target.p_health = 0;
		}
	}
	//checks the player health and sets it to 0 if goes below 0
	bool P_IsAlive()
	{
		if (this->p_health > 0)
		{
			return true;
		}
		return false;
	}
	//this prints out the status of the player after each turn
	void P_PrintStats()
	{
		std::cout << p_name << " Health: " << p_health << std::endl;
		std::cout << p_name << " Strength: " << p_strength << std::endl;
		std::cout << p_name << " Defence: " << p_defence << std::endl;
	}
};