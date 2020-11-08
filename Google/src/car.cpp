#include <iostream>
#include "../inc/Car.h"

Car::Car() {}

Car::Car(Car &c)
{
    this->m_model = c.m_model;
    this->m_speed = c.m_speed;
}

Car::Car(std::string model, int speed)
{
    try
    {
        m_model = model;
        setSpeed(speed);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Car::~Car() {}

void Car::setSpeed(int speed)
{
    if (speed >= 0)
    {
        m_speed = speed;
    }
    else
    {
        throw std::invalid_argument("Speed cannot be lower than zero");
    }
}

std::ostream &operator<<(std::ostream &out, Car &c)
{
    out << " " << c.m_model << " " << c.m_speed;
    return out;
}
