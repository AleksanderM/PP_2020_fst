#include <iostream>
#include <sstream>
#include "car.h"

#define COMMAND_LENGTH 3

void inputCars(Car *cars, int carCount)
{
    std::string model = "";
    double fuel = 0.0;
    double fuelConsumption = 0.0;

    for (int i = 0; i < carCount; i++)
    {
        std::cout << "Enter the model, fuel amd fuel consumption of the car:" << std::endl;
        std::cin >> model >> fuel >> fuelConsumption;

        cars[i] = Car(model, fuel, fuelConsumption);
    }
}

void getCommand(std::string command[])
{
    std::cout << "Enter command:" << std::endl;
    std::string line;
    std::string temp;
    std::getline(std::cin, line);
    std::stringstream ssin(line);
    int i = 0;

    while (i < COMMAND_LENGTH && std::getline(ssin, temp, ' '))
    {
        command[i] = temp;
        i++;
    }
}

void executeCommand(std::string command[], Car *cars, int carCount)
{
    std::string model = command[1];
    int distance = std::stoi(command[2]);
    bool isFound = false;

    for (int i = 0; i < carCount; i++)
    {
        if (cars[i].getModel().compare(model) == 0)
        {
            isFound = true;
            cars[i].drive(distance);
        }
    }

    if (!isFound)
    {
        std::cout << "There is no such model" << std::endl;
    }
}

int main()
{
    int carCount = 0;
    std::cout << "Enter size:" << std::endl;
    std::cin >> carCount;

    Car *cars = new Car[carCount];
    inputCars(cars, carCount);
    std::cin.ignore();

    std::string command[COMMAND_LENGTH];
    getCommand(command);

    while (command[0].compare("End") != 0)
    {
        if (command[0].compare("Drive") == 0)
        {
            executeCommand(command, cars, carCount);
        }
        else
        {
            std::cout << "Invalid command" << std::endl;
        }

        getCommand(command);
    }

    delete[] cars;
    delete[] command;

    return 0;
}