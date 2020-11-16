#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Team.h"
using namespace std;


void inputCommand(vector<string> &tokens)
{
	string input;
	cin >> input;

	istringstream iss(input);
	string temp;

	while (getline(iss, temp, ';'))
	{
		tokens.push_back(temp);
	}
}

bool teamExists(string name, vector<Team> &teams)
{
	for (auto a = teams.begin(); a != teams.end(); a++)
	{
		if (a->getName() == name)
		{
			return true;
		}
	}

	return false;
}

bool playerExists(string name, vector<Team> &teams)
{
	vector<Player *> temp;
	for (auto a = teams.begin(); a != teams.end(); a++)
	{
		temp = a->getPlayers();
		for (auto b = temp.begin(); b != temp.end(); b++)
		{
			if ((*b)->getName() == name)
			{
				return true;
			}
		}
	}
	return false;
}
void teamCommand(string name, vector<Team> &teams)
{
	if (teamExists(name, teams))
	{
		cout << "Team " << name << " already exists!" << endl;
	}
	else
	{
		
	}
}
int main()
{
	vector<Team> teams;
	bool endCommand = false;

	
}