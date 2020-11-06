#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include <string>

class Child;
std::ostream &operator<<(std::ostream &out, Child &c);

class Child
{
private:
    std::string name;
    std::string birthday;
public:
    Child();
    Child(Child &c);
    Child(std::string name, std::string birthday);
    ~Child();

    friend std::ostream &operator<<(std::ostream &out, Child &c);
};

#endif