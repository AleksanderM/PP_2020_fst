#ifndef CAR_H
#define CAR_H

#include <string>
#include "Engine.h"

class Car;
std::ostream &operator<<(std::ostream &out, Car &c);

class Car
{
private:
    std::string model;
    Engine *engine;
    int weight;
    std::string color;

public:
    Car();
    Car(std::string model, Engine *engine);
    Car(std::string model, Engine *engine, int weight);
    Car(std::string model, Engine *engine, std::string color);
    Car(std::string model, Engine *engine, int weight, std::string color);
    ~Car();

    friend std::ostream &operator<<(std::ostream &out, Car &c);
};

#endif