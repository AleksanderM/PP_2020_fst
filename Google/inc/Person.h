#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include "Company.h"
#include "Pokemon.h"
#include "Parent.h"
#include "Child.h"
#include "Car.h"

class Person
{
private:
    Company company;
    std::vector<Pokemon> pokemon;
    std::vector<Parent> parents;
    std::vector<Child> children;
    Car car;
public:
    Person();
    ~Person();

    void setCompany(Company &c);
    void addPokemon(Pokemon &p);
    void addParent(Parent &p);
    void addChild(Child &c);
    void setCar(Car &c);
};

#endif