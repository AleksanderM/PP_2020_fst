#include <iostream>
#include <string>
#include "car.h"

Car::Car() {}

Car::Car(std::string model, double fuel, double fuelConsumption)
{
    this->model = model;
    this->fuel = fuel;
    this->fuelConsumption = fuelConsumption;
    this->distanceTraveled = 0;
}

std::string Car::getModel() const
{
    return this->model;
}

void Car::drive(int distance)
{
    if (this->fuel < (distance * this->fuelConsumption))
    {
        std::cout << "Insufficient fuel for the drive" << std::endl;
    }
    else
    {
        this->fuel -= distance * this->fuelConsumption;
        this->distanceTraveled += distance;
    }
}

std::ostream& operator<<(std::ostream& out, Car& car)
{
    out << car.model << " " << car.fuel << " " << car.distanceTraveled << std::endl;
    return out;
}

Car::~Car() {}