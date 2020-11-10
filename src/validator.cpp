#include "../inc/Validator.h"

bool Validator::validateStat(int stat)
{
    if (stat >= 0 && stat <= 100)
    {
        return true;
    }

    return false;
}