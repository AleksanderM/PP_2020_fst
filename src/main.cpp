#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../inc/Team.h"

int recogniseCommand(std::string command, int commandSize)
{
    if (command == "Team" && commandSize == 2)
    {
        return 1;
    }
    else if (command == "Add" && commandSize == 8)
    {
        return 2;
    }
    else if (command == "Remove" && commandSize == 3)
    {
        return 3;
    }
    else if (command == "Rating" && commandSize == 2)
    {
        return 4;
    }
    else if (command == "END" && commandSize == 1)
    {
        return 5;
    }

    return -1;
}

void inputCommand(std::vector<std::string> &tokens)
{
    std::string input;
    std::cin >> input;

    std::istringstream iss(input);
    std::string temp;

    while (std::getline(iss, temp, ';'))
    {
        tokens.push_back(temp);
    }
}

bool teamExists(std::string name, std::vector<Team> &teams)
{
    for (auto i = teams.begin(); i != teams.end(); i++)
    {
        if (i->getName() == name)
        {
            return true;
        }
    }

    return false;
}

bool playerExists(std::string name, std::vector<Team> &teams)
{
    std::vector<Player *> temp;
    for (auto i = teams.begin(); i != teams.end(); i++)
    {
        temp = i->getPlayers();
        for (auto p = temp.begin(); p != temp.end(); p++)
        {
            if ((*p)->getName() == name)
            {
                return true;
            }
        }
    }

    return false;
}

void teamCommand(std::string name, std::vector<Team> &teams)
{
    if (teamExists(name, teams))
    {
        std::cout << "Team " << name << " already exists!" << std::endl;
    }
    else
    {
        try
        {
            teams.push_back(Team(name));
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

Team *findTeam(std::string name, std::vector<Team> &teams)
{
    for (auto i = teams.begin(); i != teams.end(); i++)
    {
        if (i->getName() == name)
        {
            return &(*i);
        }
    }

    return nullptr;
}

void parsePlayerStats(std::vector<std::string> &tokens, std::vector<Team> &teams)
{
    int endurance = std::stoi(tokens.at(3));
    int sprint = std::stoi(tokens.at(4));
    int dribble = std::stoi(tokens.at(5));
    int pass = std::stoi(tokens.at(6));
    int shot = std::stoi(tokens.at(7));

    Team *team = findTeam(tokens.at(1), teams);

    try
    {
        Stats *stats = new Stats(endurance, sprint, dribble, pass, shot);
        Player *player = new Player(tokens.at(2), stats);
        team->addPlayer(player);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void addCommand(std::vector<std::string> &tokens, std::vector<Team> &teams)
{
    if (teamExists(tokens.at(1), teams))
    {
        if (playerExists(tokens.at(2), teams))
        {
            std::cout << "Player " << tokens.at(2) << " already exists in team " << tokens.at(1) << std::endl;
        }
        else
        {
            parsePlayerStats(tokens, teams);
        }
    }
    else
    {
        std::cout << "Team " << tokens.at(1) << " does not exist!" << std::endl;
    }
}

void removeCommand(std::vector<std::string> &tokens, std::vector<Team> &teams)
{
    if (teamExists(tokens.at(1), teams))
    {
        if (playerExists(tokens.at(2), teams))
        {
            Team *team = findTeam(tokens.at(1), teams);
            team->removePlayer(tokens.at(2));
        }
        else
        {
            std::cout << "Player " << tokens.at(2) << " does not exist in team " << tokens.at(1) << std::endl;
        }
    }
    else
    {
        std::cout << "Team " << tokens.at(1) << " does not exist!" << std::endl;
    }
}

void ratingCommand(std::vector<std::string> &tokens, std::vector<Team> &teams)
{
    if (teamExists(tokens.at(1), teams))
    {
        Team *team = findTeam(tokens.at(1), teams);
        std::cout << team->getName() << " - " << team->getRating() << std::endl;
    }
    else
    {
        std::cout << "Team " << tokens.at(1) << " does not exist!" << std::endl;
    }
}

void executeCommand(bool &endCommand, std::vector<Team> &teams)
{
    std::vector<std::string> tokens;
    inputCommand(tokens);

    switch (recogniseCommand(tokens.at(0), tokens.size()))
    {
    case 1:
        teamCommand(tokens.at(1), teams);
        break;
    case 2:
        addCommand(tokens, teams);
        break;
    case 3:
        removeCommand(tokens, teams);
        break;
    case 4:
        ratingCommand(tokens, teams);
        break;
    case 5:
        endCommand = true;
        break;
    default:
        std::cout << "Invalid command" << std::endl;
        break;
    }
}

int main()
{
    std::vector<Team> teams;
    bool endCommand = false;

    while (!endCommand)
    {
        executeCommand(endCommand, teams);
    }
}