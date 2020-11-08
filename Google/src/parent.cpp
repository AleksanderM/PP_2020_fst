#include "../inc/Parent.h"
#include "../inc/Helper.h"

Parent::Parent() {}

Parent::Parent(Parent &p)
{
    this->m_name = p.m_name;
    this->m_birthday = p.m_birthday;
}

Parent::Parent(std::string name, std::string birthday)
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

Parent::~Parent() {}

std::ostream &operator<<(std::ostream &out, Parent &p)
{
    out << " " << p.m_name << " " << p.m_birthday << std::endl;
    return out;
}
