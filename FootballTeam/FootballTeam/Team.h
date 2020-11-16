#pragma once
#include<string>
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

class Team
{
public:
	Team();
	~Team();

	bool  setName(const string newName);
	
	string getName() const;

	bool addPlayer(Player player);
	bool removePlayer(string name);

	int calculateRating();
	vector<Player*> getPlayers() const;


private:
	string name;
	vector<Player*> players;
};

