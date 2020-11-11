#pragma once
#include <vector>
#include <string>
#include "Player.h"

class Team {

private:
	std::string teamName;
	int rating;
    std::vector <Player> players;

public:

	void Add(Player);
	void Remove(std::string);
	Team();
	Team(std::string teamName, int rating);


	std::string getTeamName();
	void setTeamName(std::string);

	int getRating();
	void setRating(int);

	std::vector <Player> getPlayers();
	void setPlayers(std::string);

};