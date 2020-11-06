#include "../inc/Parent.h"

Parent::Parent() {}

Parent::Parent(Parent &p)
{
    this->name = p.name;
    this->birthday = p.birthday;
}

Parent::Parent(std::string name, std::string birthday)
{
    this->name = name;
    this->birthday = birthday;
}

Parent::~Parent() {}

std::ostream &operator<<(std::ostream &out, Parent &p)
{
    out << p.name << " " << p.birthday << std::endl;
    return out;
}
