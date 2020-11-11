/*
 * Rectangle.cpp
 *
 *  Created on: 6.11.2020 ã.
 *      Author: ivan
 */

#include "Rectangle.h"
#include<string>
using namespace std;



	string Rectangle::getID(){
		return ID;
	}
	void Rectangle::setID(string x){
		ID = x;
	}

	int Rectangle::getHight(){
		return hight;
	}
	void Rectangle::setHight(int x){
		hight = x;
	}

	int Rectangle::getWidth(){
		return width;
	}
	void Rectangle::setWidth(int x){
		width = x;
	}

	int Rectangle::getCordX(){
		return cordX;
	}
	void Rectangle::setCordX(int x){
		cordX = x;
	}

	int Rectangle::getCordY(){
		return cordY;
	}
	void Rectangle::setCordY(int x){
		cordY = x;
	}

    int Rectangle::getLeft(){
    	int l;
    	l = cordX;
    	return l;
    }
    int Rectangle::getRight(){
    	int r;
    	r = cordX+width;
    	return r;
    }
    int Rectangle::getTop(){
    	int t;
    	t = cordY;
    	return t;
    }
    int Rectangle::getBottom(){
    	int b;
    	b = cordY-hight;
    	return b;
    }





