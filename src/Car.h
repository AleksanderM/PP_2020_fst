#pragma once
#include <string>
#include <iostream>
class Car {

	std::string model;
	double fuel;
	double fuelConsumption;
	int mileage;

public:

	Car();

	Car(std::string, double, double);

	Car(const Car&) = default;

	std::string getModel(void);
	
	bool drive(int);

	void printData(void);

};