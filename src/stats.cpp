#include <iostream>
#include "../inc/Validator.h"
#include "../inc/Stats.h"

Stats::Stats()
{
    int m_endurance = 0;
    int m_sprint = 0;
    int m_dribble = 0;
    int m_pass = 0;
    int m_shot = 0;
}

Stats::Stats(int endurance, int sprint, int dribble, int pass, int shot)
{
    setEndurance(endurance);
    setSprint(sprint);
    setDribble(dribble);
    setPass(pass);
    setShot(shot);
}

Stats::Stats(Stats &s)
{
    this->m_endurance = s.m_endurance;
    this->m_sprint = s.m_sprint;
    this->m_dribble = s.m_dribble;
    this->m_pass = s.m_pass;
    this->m_shot = s.m_shot;

    s.~Stats();
}

Stats::~Stats() {}

void Stats::setEndurance(int endurance)
{
    if (Validator::validateStat(endurance))
    {
        m_endurance = endurance;
    }
    else
    {
        throw std::invalid_argument("Endurance must be between 0 and 100");
    }
}

void Stats::setSprint(int sprint)
{
    if (Validator::validateStat(sprint))
    {
        m_sprint = sprint;
    }
    else
    {
        throw std::invalid_argument("Sprint must be between 0 and 100");
    }
}

void Stats::setDribble(int dribble)
{
    if (Validator::validateStat(dribble))
    {
        m_dribble = dribble;
    }
    else
    {
        throw std::invalid_argument("Dribble must be between 0 and 100");
    }
}

void Stats::setPass(int pass)
{
    if (Validator::validateStat(pass))
    {
        m_pass = pass;
    }
    else
    {
        throw std::invalid_argument("Pass must be between 0 and 100");
    }
}

void Stats::setShot(int shot)
{
    if (Validator::validateStat(shot))
    {
        m_shot = shot;
    }
    else
    {
        throw std::invalid_argument("Shot must be between 0 and 100");
    }
}

int Stats::getAverageAbility()
{
    return (m_endurance + m_sprint + m_dribble + m_pass + m_shot) / 5;
}
