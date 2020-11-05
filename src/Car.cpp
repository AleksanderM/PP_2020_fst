#pragma once
#include "Car.h"
Car::Car() 
{
	model = "";
	fuel = 0.0;
	fuelConsumption = 0.0;
	mileage = 0;
}

Car::Car(std::string nModel, double nFuel, double nFuelConsumption) 
{
	model = nModel;
	fuel = nFuel;
	fuelConsumption = nFuelConsumption;
	mileage = 0;
}

std::string Car::getModel(void)
{
	return model;
}

bool Car::drive(int nDistance) 
{

	if ( nDistance * fuelConsumption <= fuel) 
	{
		fuel -= fuelConsumption * nDistance;
		mileage += nDistance;

		return true;
	}

	std::cout << "Insufficient fuel for the drive " << "\n";
 	return false;
}

void Car::printData(void)
{
	std::cout << model << " " << fuel << " " << mileage << "\n";
}
