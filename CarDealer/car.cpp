#include "Car.h"

Car::Car() {}

Car::Car(std::string model, Engine *engine)
{
    this->model = model;
    this->engine = engine;
    this->weight = 0;
    this->color = "n/a";
}

Car::Car(std::string model, Engine *engine, int weight)
{
    this->model = model;
    this->engine = engine;
    this->weight = weight;
    this->color = "n/a";
}

Car::Car(std::string model, Engine *engine, std::string color)
{
    this->model = model;
    this->engine = engine;
    this->weight = 0;
    this->color = color;
}

Car::Car(std::string model, Engine *engine, int weight, std::string color)
{
    this->model = model;
    this->engine = engine;
    this->weight = weight;
    this->color = color;
}

Car::~Car() {}

std::ostream &operator<<(std::ostream &out, Car &c)
{
    out << c.model << ":" << std::endl;
    out << *c.engine;
    if (c.weight == 0)
    {
        out << " Weight: n/a" << std::endl;
    }
    else
    {
        out << " Weight: " << c.weight << std::endl;
    }
    
    out << " Color: " << c.color << std::endl;

    return out;
}