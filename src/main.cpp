//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int* countingSort(int length,int arr[]){

	 int temp[length];
	int min=arr[0],max=arr[0];

for(int i=0;i<length;i++){
		if(min>arr[i]){
			min = arr[i];
		}
		if(max<arr[i]){
			max = arr[i];

		}

	}

	int offset = abs(min);

     int len = max+offset+1;
     int sort[len];
   for(int i=0;i<len;i++){
	   sort[i] = 0;
   }

    for(int i =0;i<length;i++){
	sort[arr[i]+offset] += 1;
	}
    int j = 0;

      for(int i=len-1;i>=0;i--){


    	 while(sort[i] > 0){
    		  temp[j]= i-offset;
    		  j++;
    		  sort[i]--;

    	  }


      }

return temp;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
