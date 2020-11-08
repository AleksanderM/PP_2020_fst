#include "../inc/Pokemon.h"

Pokemon::Pokemon() {}

Pokemon::Pokemon(Pokemon &p)
{
    this->m_name = p.m_name;
    this->m_type = p.m_type;
}

Pokemon::Pokemon(std::string name, std::string type)
{
    m_name = name;
    m_type = type;
}

Pokemon::~Pokemon() {}

std::ostream &operator<<(std::ostream &out, Pokemon &p)
{
    out << " " << p.m_name << " " << p.m_type << std::endl;
    return out;
}