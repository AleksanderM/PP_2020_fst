#pragma once
#include <string>
class Player
{
	std::string m_name;

	int		m_durability,
			m_spring,
			m_dribble,
			m_passes,
			m_shooting,
			m_averageLevel;

public:
	Player();
	Player(std::string, int, int, int, int, int);
	~Player();
	Player(const Player&) = default;

	std::string getName(void);
	void setName(std::string);
	int getAverageLevel(void);
	bool calculateAverageLevel(void);


};