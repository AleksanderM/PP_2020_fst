#include "../inc/Player.h"

Player::Player(){}

Player::Player(std::string name, Stats &stats)
{
    m_name = name;
    m_stats = Stats(stats);
}

Player::~Player() 
{
    m_stats.~Stats();
}

std::string Player::getName()
{
    return m_name;
}

int Player::getAvgStat()
{
    return m_stats.getAverageAbility();
}

std::ostream &Player::operator<<(std::ostream &out)
{
    out << " Name: " << m_name << std::endl;
    out << " Avg stat: " << m_stats.getAverageAbility() << std::endl;

    return out;
}