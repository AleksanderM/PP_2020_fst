#include "Player.h"

Player::Player() {
	this->playerName = "";
	this->playerStatistics = 0;
}

Player::Player(std::string playerName, int playerStatistics) {
	this->playerName = playerName;
	this->playerStatistics = playerStatistics;
}

void Player::setPlayerName(std::string var) {
	
}
std::string Player::getPlayerName(){
	return playerName;
}

int Player::getPlayerStatistics() {
	return playerStatistics;
}