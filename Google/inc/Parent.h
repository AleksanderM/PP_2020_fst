#ifndef PARENT_H
#define PARENT_H

#include <iostream>
#include <string>

class Parent;
std::ostream &operator<<(std::ostream &out, Parent &p);

class Parent
{
private:
    std::string name;
    std::string birthday;
public:
    Parent();
    Parent(Parent &p);
    Parent(std::string name, std::string birthday);
    ~Parent();

    friend std::ostream &operator<<(std::ostream &out, Parent &p);
};

#endif