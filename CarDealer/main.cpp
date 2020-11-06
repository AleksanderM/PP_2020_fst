#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "Car.h"
#include "Engine.h"

static int value;

void getCommand(std::vector<std::string> &tokens)
{
    std::string line;
    std::string temp;
    std::getline(std::cin, line);
    std::stringstream ssin(line);

    while (std::getline(ssin, temp, ' '))
    {
        tokens.push_back(temp);
    }
}

bool tryParse(std::string token)
{
    std::stringstream buffer(token);
    return buffer >> value && buffer.eof();
}

Engine *findEngine(Engine *engines, int engineCount, std::string engineModel)
{
    for (int i = 0; i < engineCount; i++)
    {
        if (engines[i].getModel().compare(engineModel) == 0)
        {
            return &engines[i];
        }
    }

    return nullptr;
}

int main()
{
    int engineCount = 0;
    std::cin >> engineCount;
    std::cin.ignore();

    Engine *engines = new Engine[engineCount];
    std::vector<std::string> tokens;

    for (int i = 0; i < engineCount; i++)
    {
        getCommand(tokens);
        switch (tokens.size())
        {
        case 2:
            engines[i] = Engine(tokens.at(0), stoi(tokens.at(1)));
            break;
        case 3:
            if (tryParse(tokens.at(2)))
            {
                engines[i] = Engine(tokens.at(0), stoi(tokens.at(1)), value);
            }
            else
            {
                engines[i] = Engine(tokens.at(0), stoi(tokens.at(1)), tokens.at(2));
            }

            break;
        case 4:
            engines[i] = Engine(tokens.at(0), stoi(tokens.at(1)), stoi(tokens.at(2)), tokens.at(3));
            break;
        default:
            std::cout << "Invalid command" << std::endl;
            i--;
            break;
        }

        tokens.clear();
    }

    int carCount = 0;
    std::cin >> carCount;
    std::cin.ignore();

    Car *cars = new Car[carCount];
    Engine *pEngine;

    for (int i = 0; i < carCount; i++)
    {
        getCommand(tokens);
        switch (tokens.size())
        {
        case 2:
            pEngine = findEngine(engines, engineCount, tokens.at(1));
            if (pEngine == nullptr)
            {
                std::cout << "Engine does not exist" << std::endl;
                i--;
            }
            else
            {
                cars[i] = Car(tokens.at(0), pEngine);
            }

            break;
        case 3:
            pEngine = findEngine(engines, engineCount, tokens.at(1));
            if (pEngine == nullptr)
            {
                std::cout << "Engine does not exist" << std::endl;
                i--;
            }
            else
            {
                if (tryParse(tokens.at(2)))
                {
                    cars[i] = Car(tokens.at(0), pEngine, stoi(tokens.at(2)));
                }
                else
                {
                    cars[i] = Car(tokens.at(0), pEngine, tokens.at(2));
                }
            }

            break;
        case 4:
            pEngine = findEngine(engines, engineCount, tokens.at(1));
            if (pEngine == nullptr)
            {
                std::cout << "Engine does not exist" << std::endl;
                i--;
            }
            else
            {
                cars[i] = Car(tokens.at(0), pEngine, stoi(tokens.at(2)), tokens.at(3));
            }
            break;

        default:
            std::cout << "Invalid command" << std::endl;
            i--;
            break;
        }

        tokens.clear();
    }

    std::cout << std::endl;

    for (int i = 0; i < carCount; i++)
    {
        std::cout << cars[i] << std::endl;
    }
    
    delete[] engines;
    delete[] cars;
}