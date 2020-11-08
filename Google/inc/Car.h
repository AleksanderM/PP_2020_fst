#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car;
std::ostream &operator<<(std::ostream &out, Car &c);

class Car
{
private:
    std::string m_model;
    int m_speed;

    void setSpeed(int speed);

public:
    Car();
    Car(Car &c);
    Car(std::string model, int speed);
    ~Car();

    friend std::ostream &operator<<(std::ostream &out, Car &c);
};

#endif