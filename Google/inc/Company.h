#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>

class Company;
std::ostream &operator<<(std::ostream &out, Company &c);

class Company
{
private:
    std::string name;
    std::string branch;
    double salary;
public:
    Company();
    Company(Company &c);
    Company(std::string name, std::string branch, double salary);
    ~Company();

    friend std::ostream &operator<<(std::ostream &out, Company &c);
};

#endif