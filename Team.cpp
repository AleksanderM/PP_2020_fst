#include "Team.h"

Team::Team()
{
	m_name			= "n/a";
	m_numPlayers	= 0;
	m_rating		= 0;
};

Team::Team(std::string n_name)
{
	m_name			= n_name;
	m_numPlayers	= 0;
	m_rating		= 0;
};

bool Team::addPlayer(Player& n_player) 
{
	m_players[n_player.getName()] = n_player;
	calculateRating();

	return true;

}

bool Team::removePlayer(std::string n_player)
{
	bool t_flag = true;
	for (auto& it : m_players) 
	{
		if (it.first.compare(n_player) == 0 ) 
		{
			m_players.erase(n_player);
			t_flag = false;
			calculateRating();
			break;
		}
		
	}
	if (t_flag) 
	{
		std::cout << "Player " << n_player << " is not in " << m_name << " team.\n";
		return false;
	}

	return true;
}

bool Team::calculateRating(void) 
{
	int temp_rating = 0;
	int iterations	= 0;
	for (auto& it : m_players) 
	{
		iterations++;
		temp_rating += it.second.getAverageLevel();
	}

	if (iterations > 0)
	{
		m_rating = llround(temp_rating / iterations);
	}
	else 
	{
		m_rating = 0;
	}
	return true;
}

Team::~Team()
{
	m_players.clear();
}

std::string Team::getName(void) const 
{
	return m_name;
}

int Team::getRating() const
{
	return m_rating;
}
