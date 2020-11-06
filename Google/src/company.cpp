#include <iomanip>
#include "../inc/Company.h"

Company::Company() {}

Company::Company(Company &c)
{
    this->name = c.name;
    this->branch = c.branch;
    this->salary = c.salary;
}

Company::Company(std::string name, std::string branch, double salary)
{
    this->name = name;
    this->branch = branch;
    this->salary = salary;
}

Company::~Company() {}

std::ostream &operator<<(std::ostream &out, Company &c)
{
    out << c.name << " " << c.branch << std::fixed << std::setprecision(2) << " " << c.salary << std::endl;

    return out;
}
