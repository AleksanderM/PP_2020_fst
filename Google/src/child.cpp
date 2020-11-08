#include <iostream>
#include <string>
#include <regex>
#include "../inc/Child.h"
#include "../inc/Helper.h"

Child::Child() {}

Child::Child(Child &c)
{
    this->m_name = c.m_name;
    this->m_birthday = c.m_birthday;
}

Child::Child(std::string name, std::string birthday)
{
    try
    {
        m_name = name;
        Helper::validateBirthday(birthday, m_birthday);
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
}

Child::~Child() {}

std::ostream &operator<<(std::ostream &out, Child &c)
{
    out << " " << c.m_name << " " << c.m_birthday << std::endl;
    return out;
}
