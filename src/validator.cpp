#include <regex>
#include "../inc/Validator.h"

bool Validator::validateStat(int stat)
{
    if (stat >= 0 && stat <= 100)
    {
        return true;
    }

    return false;
}

bool Validator::validateName(std::string name)
{
    std::regex rgx("[ ]+");
    if (std::regex_search(name, rgx) || name.empty())
    {
        return false;
    }

    return true;
}