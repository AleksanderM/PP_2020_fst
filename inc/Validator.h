#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

class Validator
{
public:
    static bool validateName(std::string name);
    static bool validateStat(int stat);
};

#endif