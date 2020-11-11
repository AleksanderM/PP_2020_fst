#pragma once
#include "Player.h"
#include <unordered_map>
#include <cmath> 
#include <iostream>

class Team
{
	std::string			m_name;

	int					m_numPlayers,
						m_rating;

	std::unordered_map<std::string, Player> m_players;

public:

	Team();
	Team(std::string);
	~Team();
	Team(const Team&) = default;
	std::string getName(void) const;
	int getRating() const;

	bool addPlayer(Player&);
	bool removePlayer(std::string);
	bool calculateRating(void);

};