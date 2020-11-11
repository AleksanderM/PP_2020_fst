#include "Player.h"

Player::Player()
{
	m_name			= "n/a";
	m_durability	= 0;
	m_spring		= 0;
	m_dribble		= 0;
	m_passes		= 0;
	m_shooting		= 0;
	m_averageLevel	= 0;
};

Player::Player(std::string n_name, int n_durability, int n_spring, int n_dribble, int n_passes, int n_shooting)
{
	m_name = n_name;
	m_durability = n_durability;
	m_spring = n_spring;
	m_dribble = n_dribble;
	m_passes = n_passes;
	m_shooting = n_shooting;
	m_averageLevel = 0;

	calculateAverageLevel();

};

Player::~Player() 
{
	//doing nothing ama da ima
}

std::string Player::getName(void) 
{
	return m_name;
}

int Player::getAverageLevel(void) 
{
	return m_averageLevel;
}

void Player::setName(std::string n_name)
{
	m_name = n_name;
}


bool Player::calculateAverageLevel(void) 
{
	double temp = 0;

	temp += m_durability + m_spring + m_dribble + m_passes + m_shooting;

	m_averageLevel = llround(temp / 5);

	return true;
}
