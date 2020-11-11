/*
 * Car.cpp
 *
 *  Created on: 5.11.2020 ã.
 *      Author: ivan
 */
#include "Car.h"
#include<string>
using namespace std;


double Car::getFuel(){
	 return fuel;
 }
void Car::setFuel(double x){
	fuel = x;
}


string Car::getModel(){
	return model;
}
void Car::setModel(string x){
	model = x;
}


double Car::getExpense(){
	return expense;
}
void Car::setExpense(double x){
	expense = x;
}


double Car::getTravel(){
	return travel;
}
void Car::setTravel(double x){
	travel = x;
}

int Car::getN(){
	return n;
}
void Car::setN(int x){
	n = x;
}


