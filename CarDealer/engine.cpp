#include "Engine.h"

Engine::Engine() {}

Engine::Engine(std::string model, int power)
{
    this->model = model;
    this->power = power;
    this->displacement = 0;
    this->efficiency = "n/a";
}

Engine::Engine(std::string model, int power, int displacement)
{
    this->model = model;
    this->power = power;
    this->displacement = displacement;
    this->efficiency = "n/a";
}

Engine::Engine(std::string model, int power, std::string efficiency)
{
    this->model = model;
    this->power = power;
    this->displacement = 0;
    this->efficiency = efficiency;
}

Engine::Engine(std::string model, int power, int displacement, std::string efficiency)
{
    this->model = model;
    this->power = power;
    this->displacement = displacement;
    this->efficiency = efficiency;
}

Engine::~Engine() {}

std::string Engine::getModel() const
{
    return this->model;
}

std::ostream &operator<<(std::ostream &out, Engine &e)
{
    out << " " << e.model << ":" << std::endl;
    out << "   Power: " << e.power << std::endl;
    if (e.displacement == 0)
    {
        out << "   Displacement: n/a" << std::endl;
    }
    else
    {
        out << "   Displacement: " << e.displacement << std::endl;
    }

    out << "   Efficiency: " << e.efficiency << std::endl;
    
    return out;
}