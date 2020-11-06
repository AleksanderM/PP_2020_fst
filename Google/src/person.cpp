#include "../inc/Person.h"

Person::Person() {}

Person::~Person() {}

void Person::setCompany(Company &c)
{
    this->company = Company(c);
    c.~Company();
}

void Person::addPokemon(Pokemon &p)
{
    this->pokemon.push_back(p);
}

void Person::addParent(Parent &p)
{
    this->parents.push_back(p);
}

void Person::addChild(Child &c)
{
    this->children.push_back(c);
}

void Person::setCar(Car &c)
{
    this->car = Car(c);
    c.~Car();
}
