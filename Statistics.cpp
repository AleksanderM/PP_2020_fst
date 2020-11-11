#include "Statistics.h"
#include <stdexcept>


Statistics::Statistics() {
	this->durability = 0;
	this->sprint = 0;
	this->dribble = 0;
	this->passes = 0;
	this->shooting = 0;
}

Statistics::Statistics(int durability, int sprint, int dribble, int passes, int shooting) {
	setDurability(durability);
	setSprint(sprint);
	setDribble(dribble);
	setPasses(passes);
	setShooting(shooting);
}

void Statistics::setDurability(int var) {
	if (var < 0 || var > 100) {
      throw std::invalid_argument("Durability should be between 0 and 100.");
    }else {
      this->durability = durability;
	}
}
int Statistics::getDurability() {
	return durability;
}

void Statistics::setSprint(int var) {
	if (var < 0 || var > 100) {

		throw std::invalid_argument("Durability should be between 0 and 100.");
	}else {

		this->sprint = sprint;
	}
}
int Statistics::getSprint() {
	return sprint;
}

void Statistics::setDribble(int var) {
	if (var < 0 || var > 100) {
		throw std::invalid_argument("Durability should be between 0 and 100.");
	}
	else {
		this->dribble = dribble;
	}
}
int Statistics::getDribble() {
	return dribble;
}

void Statistics::setPasses(int var) {
	if (var < 0 || var > 100) {
		throw std::invalid_argument("Durability should be between 0 and 100.");
	}
	else {
		this->passes = passes;
	}
}
int Statistics::getPasses() {
	return passes;
}

void Statistics::setShooting(int var) {
	if (var < 0 || var > 100) {
		throw std::invalid_argument("Durability should be between 0 and 100.");
	}
	else {
		this->shooting = shooting;
	}
}
int Statistics::getShooting() {
	return shooting;
}

int Statistics::


