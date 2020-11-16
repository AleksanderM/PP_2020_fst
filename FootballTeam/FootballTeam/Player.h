#pragma once
#include<string>
using namespace std;

class Player
{
public:
	Player();
	~Player();

	bool setName(const string newName);
	bool setEndurance(const int newEndurance);
	bool setSprint(const int newSprint);
	bool setDribble(const int newDribble);
	bool setPassing(const int newPassing);
	bool setShooting(const int newShooting);


	int getStatistic();
	string getName() const;


private:

	string name;
	int endurance, sprint, dribble, passing, shooting;
};

