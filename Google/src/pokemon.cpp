#include "../inc/Pokemon.h"

Pokemon::Pokemon() {}

Pokemon::Pokemon(Pokemon &p)
{
    this->name = p.name;
    this->type = p.type;
}

Pokemon::Pokemon(std::string name, std::string type)
{
    this->name = name;
    this->type = type;
}

Pokemon::~Pokemon() {}

std::ostream &operator<<(std::ostream &out, Pokemon &p)
{
    out << p.name << " " << p.type << std::endl;
    return out;
}