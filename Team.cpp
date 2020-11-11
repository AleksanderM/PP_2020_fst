#include "Team.h"

void Team::Add(Player player) {

	players.push_back(player);
	
}

void Team::Remove(std::string name) {

	for (int i = 0; i < players.size(); i++) {

		if (players.at(i).getPlayerName() == name) {
			players.erase(players.begin() + i);
		}
	}
}
Team::Team() {
	this->teamName = "";
	this->rating = 0;
}

Team::Team(std::string teamName, int rating) {
	this->teamName = teamName;
	this->rating = rating;
}

void Team::setTeamName(std::string) {

}
std::string Team::getTeamName() {
	return teamName;
}

void Team::setRating(int) {

}int Team::getRating() {
	return rating;
}

void Team::setPlayers(std::string) {

}
std::vector <Player> Team::getPlayers() {
	return this->players;
}