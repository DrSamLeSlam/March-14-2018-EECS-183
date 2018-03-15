/**
* Point.cpp
*
* EECS 183
* Lab 6: Classes and File I/O
* Taken from Project 4: CoolPics
*
* <#Name#>
* <#uniqname#>
*
* <#Description#>
*/

#include "Point.h"

// for the declaration of DIMENSION
#include <iostream>
#include "utility.h"


// TODO: implement two constructors, setX, getX, setY, getY, read, write, checkRange.
Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int xVal, int yVal) {
	x = checkRange(xVal);
	y = checkRange(yVal);
}

void Point::setX(int xVal) {
	x = checkRange(xVal);

	return;
}

int Point::getX() {
	return x;
}

void Point::setY(int yVal) {
	y = checkRange(yVal);
	return;
}

int Point::getY() {
	return y;
}

void Point::read(istream& ins) {
	char trash;
	ins >> trash;
	ins >> x;
	x = checkRange(x);
	ins >> trash;
	ins >> y;
	y = checkRange(y);
	ins >> trash;
	return;
}

void Point::write(ostream& outs) {
	outs << "(" << x << ", " << y << ")" << endl;
	return;
}

int Point::checkRange(int val) {

	if (val >= 0 and val < DIMENSION) {
		return val;
	}
	else {
		if (val >= DIMENSION) {
			return DIMENSION - 1;
		}

		else {
			return 0;
		}
	}

}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Point& pt)
{
	pt.read(ins);
	return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
	pt.write(outs);
	return outs;
}

