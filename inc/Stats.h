#ifndef STATS_H
#define STATS_H

class Stats
{
private:
    int m_endurance;
    int m_sprint;
    int m_dribble;
    int m_pass;
    int m_shot;

    void setEndurance(int endurance);
    void setSprint(int sprint);
    void setDribble(int dribble);
    void setPass(int pass);
    void setShot(int shot);

public:
    Stats();
    Stats(int endurance, int sprint, int dribble, int pass, int shot);
    Stats(Stats &s);
    ~Stats();
    int getAverageAbility();
};

#endif