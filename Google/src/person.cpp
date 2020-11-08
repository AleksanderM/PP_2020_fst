#include "../inc/Person.h"

Person::Person() {}

Person::~Person() {}

void Person::setName(std::string name)
{
    m_name = name;
}

void Person::setCompany(Company &c)
{
    m_company = Company(c);
    c.~Company();
}

void Person::addPokemon(Pokemon &p)
{
    m_pokemon.push_back(p);
}

void Person::addParent(Parent &p)
{
    m_parents.push_back(p);
}

void Person::addChild(Child &c)
{
    m_children.push_back(c);
}

void Person::setCar(Car &c)
{
    m_car = Car(c);
    c.~Car();
}

std::ostream &operator<<(std::ostream &out, Person &p)
{
    out << p.m_name << std::endl;
    out << "Company:" << std::endl
        << p.m_company;
    out << "Car:" << std::endl
        << p.m_car;
    out << "Pokemon:" << std::endl;
    for (auto i = p.m_pokemon.begin(); i != p.m_pokemon.end(); i++)
    {
        out << *i;
    }

    out << "Parents:" << std::endl;
    for (auto i = p.m_parents.begin(); i != p.m_parents.end(); i++)
    {
        out << *i;
    }

    out << "Children:" << std::endl;
    for (auto i = p.m_children.begin(); i != p.m_children.end(); i++)
    {
        out << *i;
    }

    return out;
}