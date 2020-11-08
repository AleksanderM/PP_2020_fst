#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

class Pokemon;
std::ostream &operator<<(std::ostream &out, Pokemon &p);

class Pokemon
{
private:
    std::string m_name;
    std::string m_type;
public:
    Pokemon();
    Pokemon(Pokemon &p);
    Pokemon(std::string name, std::string type);
    ~Pokemon();

    friend std::ostream &operator<<(std::ostream &out, Pokemon &p);
};

#endif