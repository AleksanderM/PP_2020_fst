#include <iomanip>
#include "../inc/Company.h"

Company::Company() {}

Company::Company(Company &c)
{
    this->m_name = c.m_name;
    this->m_branch = c.m_branch;
    this->m_salary = c.m_salary;
}

Company::Company(std::string name, std::string branch, double salary)
{
    try
    {
        m_name = name;
        m_branch = branch;
        m_salary = salary;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Company::~Company() {}

void Company::setSalary(double salary)
{
    if (salary >= 0)
    {
        m_salary = salary;
    }
    else
    {
        throw std::invalid_argument("Invalid salary");
    }
}

std::ostream &operator<<(std::ostream &out, Company &c)
{
    out << " " << c.m_name << " " << c.m_branch << std::fixed << std::setprecision(2) << " " << c.m_salary << std::endl;

    return out;
}
