#ifndef HELPER_H
#define HELPER_H

#include <string>

class Helper
{
public:
    static bool isLeapYear(int year);
    static bool validDay(int day, int month, int year);
    static void validateBirthday(std::string birthday, std::string &m_birthday);
};

#endif