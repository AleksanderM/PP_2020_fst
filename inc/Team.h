#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

class Team
{
private:
    std::string m_name;
    int m_rating;
    std::vector<Player> m_players;

    void setName(std::string name);
    void calculateRating();

public:
    Team();
    Team(std::string name);
    ~Team();

    void addPlayer(Player &p);
    void removePlayer(std::string name);
    int getRating();

    std::ostream &operator<<(std::ostream &out);
};

#endif