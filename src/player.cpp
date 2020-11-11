#include "../inc/Player.h"
#include "../inc/Validator.h"

Player::Player() {}

Player::Player(std::string name, Stats *stats)
{
    setName(name);
    m_stats = Stats(*stats);
}

Player::Player(Player &p)
{
    this->m_name = p.m_name;
    this->m_stats = Stats(p.m_stats);
}

Player::~Player()
{
    m_stats.~Stats();
}

void Player::setName(std::string name)
{
    if (Validator::validateName(name))
    {
        m_name = name;
    }
    else
    {
        throw std::invalid_argument("A name should not be empty.");
    }
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