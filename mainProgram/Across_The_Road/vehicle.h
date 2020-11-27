#ifndef vehicle_h
#define vehicle_h

#include <iostream>
using namespace std;

class Vehicle {
private:
	int mX, mY;
public:
	virtual void Move(int _x, int _y);
};

class Truck : public Vehicle {

public:
	void Move(int _x, int _y);
};

class Car : public Vehicle {

public:
	void Move(int _x, int _y);
};

#endif