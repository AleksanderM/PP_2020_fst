#pragma once

class Statistics {

private:
	int durability, sprint, dribble, passes, shooting;

public:
	Statistics();
	Statistics(int durability, int sprint, int dribble, int passes, int shooting);

	int getDurability();
	void setDurability(int);

	int getSprint();
	void setSprint(int);

	int getDribble();
	void setDribble(int);

	int getPasses();
	void setPasses(int);

	int getShooting();
	void setShooting(int);

};