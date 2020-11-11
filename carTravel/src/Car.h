/*
 * Car.h
 *
 *  Created on: 5.11.2020 ã.
 *      Author: ivan
 */
#include <string>
using namespace std;


class Car{
public:
	double getFuel();
   void setFuel(double x);

   string getModel();
   void setModel(string  x);

   double getExpense();
   void setExpense(double x);

   double getTravel();
   void setTravel(double x);

   int getN();
   void setN(int x);

   void Drive(Car arr[]);




private:
	string model;
	double fuel=0,expense=0,travel=0;
	int n=0;
};

