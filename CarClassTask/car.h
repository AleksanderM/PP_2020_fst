#ifndef CAR_CLASS
#define CAR_CLASS

#include <string>

class Car;
std::ostream& operator<<(std::ostream& out, Car& car);

class Car
{
private:
    std::string model;
    double fuel;
    double fuelConsumption;
    int distanceTraveled;

public:
    Car();
    Car(std::string model, double fuel, double fuelConsumption);
    ~Car();

    std::string getModel() const;

    void drive(int distance);
    friend std::ostream& operator<<(std::ostream& out, Car& car);
};

#endif