#include "../inc/Team.h"
#include "../inc/Validator.h"

Team::Team() {}

Team::Team(std::string name)
{
    try
    {
        setName(name);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Team::~Team() {}

void Team::setName(std::string name)
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

void Team::calculateRating()
{
    m_rating = 0;

    for (auto i = m_players.begin(); i != m_players.end(); i++)
    {
        m_rating += i->getAvgStat();
    }

    m_rating /= m_players.size();
}

void Team::addPlayer(Player &p)
{
    m_players.push_back(p);
    std::cout << "Added player " << p.getName() << std::endl;
}

void Team::removePlayer(std::string name)
{
    bool isFound = false;

    for (auto i = m_players.begin(); i != m_players.end(); i++)
    {
        if (i->getName().compare(name) == 0)
        {
            isFound = true;
            m_players.erase(i);
            std::cout << "Removed player " << name << std::endl;
            break;
        }
    }

    if (!isFound)
    {
        std::cout << "Player: " << name << " is not in " << m_name << " team" << std::endl;
    }
}

int Team::getRating()
{
    return m_rating;
}

std::ostream &Team::operator<<(std::ostream &out)
{
    out << "Team: " << m_name << std::endl;
    out << "Rating: " << m_rating << std::endl;
    out << "Players:" << std::endl;

    for (auto i = m_players.begin(); i != m_players.end(); i++)
    {
        out << (i - m_players.begin());
    }

    return out;
}