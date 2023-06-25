#include "scoreboard.h"
#include <iostream>
#include <vector>
#include <algorithm>

void ScoreBoard::AddPlayer(const std::string& playerID)
{
	if (playerDetails.count(playerID) == 0)
		playerDetails.emplace(playerID, 0);
	else
		std::cout << "This player already exists\n";
}

void ScoreBoard::RemovePlayer(const std::string& playerID)
{
	if (playerDetails.count(playerID) == 0)
		std::cout << "This player does not exist\n";
	else
		playerDetails.erase(playerID);
}

void ScoreBoard::UpdateScore(const std::string& playerID, int score)
{
	if (playerDetails.count(playerID) == 0)
		std::cout << "This player does not exist\n";
	else
	{
		playerDetails.at(playerID) = score;
		std::cout << playerID << " score has been updated to " << score << std::endl;
	}

}

int ScoreBoard::GetScore(const std::string& playerID)
{
	return playerDetails.at(playerID);
}

void ScoreBoard::TopFivePlayers()
{
	std::vector<std::pair<std::string, int>> topFive(playerDetails.begin(), playerDetails.end());
	//use of a lamda predicate to sort by the second value in the pairs
	std::sort(topFive.begin(), topFive.end(), [](const auto& lhs, const auto& rhs) {
		return lhs.second < rhs.second;
		});
	int count = 0;
	for (auto& pair : topFive)
	{
		if (count >= 5)
			break;
		std::cout << pair.first << " : " << pair.second << std::endl;
		count++;
	}
}