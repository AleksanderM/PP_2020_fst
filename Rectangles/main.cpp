#include <iostream>
#include "rectangle.h"

int main()
{
    int rectCount = 0;
    std::cin >> rectCount;
    int overlapChecksCount = 0;
    std::cin >> overlapChecksCount;

    Rectangle* rectangles = new Rectangle[rectCount];
    
    for (int i = 0; i < rectCount; i++)
    {
        std::string id;
        int width;
        int heigth;
        int x;
        int y;

        std::cin >> id >> width >> heigth >> x >> y;

        rectangles[i] = Rectangle(id, width, heigth, x, y);
    }


    for (int i = 0; i < overlapChecksCount; i++)
    {
        std::string id1;
        std::string id2;
        std::cin >> id1 >> id2;
        
        if (id1.compare(id2) == 0)
        {
            std::cout << true << std::endl;
        }
        else
        {
            Rectangle* r1 = nullptr;
            Rectangle* r2 = nullptr;

            for (int j = 0; j < rectCount && (r1 == nullptr || r2 == nullptr); j++)
            {
                if (rectangles[j].getId().compare(id1) == 0)
                {
                    r1 = &rectangles[j];
                }

                if (rectangles[j].getId().compare(id2) == 0)
                {
                    r2 = &rectangles[j];
                }
            }

            if (r1 == nullptr || r2 == nullptr)
            {
                std::cout << "Invalid ids" << std::endl;
                i--;
            }
            else
            {
                std::cout << r1->overlaps(*r2) << std::endl;
            }
        }
    }

    delete[] rectangles;
}