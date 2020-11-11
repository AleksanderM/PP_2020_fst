//============================================================================
// Name        : zastupvaneNaPravougalnici.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Rectangle.h"

int main() {

	Rectangle myRect;
	int n,m;

	cout << "enter n & m"<<endl;
	cin >> n >> m;
	Rectangle arr[n];

	for(int i=0;i<n;i++){
		arr[i]= myRect;
	}
      int Ncopy = n;
	while(n>0){
		int h,w,x,y;
		string id;
	cin >> id >> w >> h >> x >> y;
		myRect.setID(id);
		myRect.setWidth(w);
		myRect.setHight(h);
		myRect.setCordX(x);
		myRect.setCordY(y);
           n--;
	}
      n=Ncopy;
	while(m>0){
		string idA,idB;
		cin >> idA >> idB;

		Rectangle objA,objB;

		for(int i=0;i<n;i++){
		myRect = arr[i];

		if(myRect.getID()== idA){
			objA = myRect;

		}else if(myRect.getID()== idB){
			objB = myRect;
		}
		}

		  if(objA.getLeft() < objB.getRight() && objA.getRight() > objB.getLeft() && objA.getTop() > objB.getBottom() && objA.getBottom() < objB.getTop()){
			  cout << "true" << endl;
		  }else{
			  cout << "false" << endl;
		  }


		m--;
	}



}
