#include "../inc/Child.h"

Child::Child() {}

Child::Child(Child &c)
{
    this->name = c.name;
    this->birthday = c.birthday;
}

Child::Child(std::string name, std::string birthday)
{
    this->name = name;
    this->birthday = birthday;
}

Child::~Child() {}

std::ostream &operator<<(std::ostream &out, Child &c)
{
    out << c.name << " " << c.birthday << std::endl;
    return out;
}
