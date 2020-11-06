#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>

class Engine;
std::ostream &operator<<(std::ostream &out, Engine &e);

class Engine
{
private:
    std::string model;
    int power;
    int displacement;
    std::string efficiency;

public:
    Engine();
    Engine(std::string model, int power);
    Engine(std::string model, int power, int displacement);
    Engine(std::string model, int power, std::string efficiency);
    Engine(std::string model, int power, int displacement, std::string efficiency);
    ~Engine();

    std::string getModel() const;
    friend std::ostream &operator<<(std::ostream &out, Engine &e);
};

#endif