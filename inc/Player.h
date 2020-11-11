#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "../inc/Stats.h"

class Player
{
private:
    std::string m_name;
    Stats m_stats;

    void setName(std::string name);

public:
    Player();
    Player(std::string name, Stats* stats);
    Player(Player &p);
    ~Player();

    std::string getName();
    int getAvgStat();

    std::ostream &operator<<(std::ostream &out);
};

#endif