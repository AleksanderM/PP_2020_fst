#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <string>
#include "Company.h"
#include "Pokemon.h"
#include "Parent.h"
#include "Child.h"
#include "Car.h"

class Person;
std::ostream &operator<<(std::ostream &out, Person &p);

class Person
{
private:
    std::string m_name;
    Company m_company;
    std::vector<Pokemon> m_pokemon;
    std::vector<Parent> m_parents;
    std::vector<Child> m_children;
    Car m_car;

public:
    Person();
    ~Person();

    void setName(std::string m_name);
    void setCompany(Company &c);
    void addPokemon(Pokemon &p);
    void addParent(Parent &p);
    void addChild(Child &c);
    void setCar(Car &c);

    friend std::ostream &operator<<(std::ostream &out, Person &p);
};

#endif