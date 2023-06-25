#pragma once
#include <string>
#include <map>

class ScoreBoard
{
public:
	ScoreBoard() {};
	void AddPlayer(const std::string& playerID);
	void RemovePlayer(const std::string& playerID);
	void UpdateScore(const std::string&, int score);
	int GetScore(const std::string& playerID);
	void TopFivePlayers();

private:
	std::map<std::string, int> playerDetails;
};