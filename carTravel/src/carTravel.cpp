//============================================================================
// Name        : carTravel.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Car.h"
#include <iostream>
using namespace std;


int main() {
 Car MyCar;
   int n = 0;
 cin >> n;
 MyCar.setN(n);
 Car arr[MyCar.getN()];
 for(int i=0;i<MyCar.getN();i++){
	  Car temp;
	  string temp2;
	  double temp3;
	  cout << "Enter Model" << endl;
	  cin >> temp2;
	  temp.setModel(temp2);

	  cout << "Enter fuel" << endl;
	  cin >> temp3;
	  temp.setFuel(temp3);

	  cout << "enter expense" << endl;
	  cin >> temp3;
	  temp.setExpense(temp3);

	  arr[i] = temp;
  }

 while(true){
	 string temp,carModel;
	 double distance;
	 cin >> temp;
	 string x = "end";
	 if(temp == x){
		 break;
	 }
     cin >> carModel >> distance;
		 for(int i=0;i<MyCar.getN();i++){
			Car temp;
			string tempS;
			temp = arr[i];
			tempS = temp.getModel();
			 if(tempS==carModel){
				 double tempE;
				 tempE = temp.getExpense();
				 tempE = tempE*distance;
            	 double tempF= temp.getFuel();
            	 if(tempF-tempE>=0){
            	 tempF -= tempE;
            	temp.setFuel(tempF);
            	distance += temp.getTravel();
            	temp.setTravel(distance);
            	arr[i] = temp;
            	 }else{
            		 cout << "Insufficient fuel for the drive"<<endl;
            	 }
             }
		 }

	 }
 for(int i=0;i<MyCar.getN();i++){
	 Car temp;
	 temp = arr[i];
	 cout << temp.getModel() << " " << temp.getFuel() << " " <<  temp.getTravel() << endl;
 }


}
