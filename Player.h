#pragma once
#include <string>
class Player {

private:
    std::string playerName;
    int playerStatistics;

public:

    Player();
    Player(std::string playerName, int playerStatistics);


    std::string getPlayerName();
    void setPlayerName(std::string);

    int getPlayerStatistics();
    void setPlayerStatistics(int);
    
};