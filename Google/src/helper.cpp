#include <string>
#include <regex>
#include "../inc/Helper.h"


bool Helper::isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }

    return false;
}

bool Helper::validDay(int day, int month, int year)
{
    switch (month)
    {
    case 2:
        if (Helper::isLeapYear(year))
        {
            if (day > 28)
            {
                return false;
            }

            return true;
        }
        else
        {
            if (day > 29)
            {
                return false;
            }

            return true;
        }

        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return true; //Already checked if day is valid i.e. day <= 31
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day > 30)
        {
            return false;
        }

        return true;
        break;
    default:
        return false;
        break;
    }
}

void Helper::validateBirthday(std::string birthday, std::string &m_birthday)
{
    std::regex rgx("(\\d{2})/(\\d{2})/(\\d{4})");
    std::smatch match;

    if (std::regex_search(birthday, match, rgx))
    {
        int day = std::stoi(match.str(1));
        int month = std::stoi(match.str(2));
        int year = std::stoi(match.str(3));

        if (year < 1900 || year > 2020 || day < 1 || day > 31)
        {
            throw std::invalid_argument("Invalid date");
        }
        else
        {
            if (Helper::validDay(day, month, year))
            {
                m_birthday = birthday;
            }
            else
            {
                throw std::invalid_argument("Invalid day corresponding to given month");
            }
        }
    }
    else
    {
        throw std::invalid_argument("Invalid date format");
    }
}