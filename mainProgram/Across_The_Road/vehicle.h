#ifndef vehicle_h
#define vehicle_h

#include "includePath.h"

class Vehicle {
private:
	float mX, mY;
public:
	//Constructor
	Vehicle();
	Vehicle(float, float);

	float X();
	float Y();
	void X(float);
	void Y(float);
	virtual void Move(int _x, int _y);
};

class Truck : public Vehicle {
private:
	sf::ConvexShape convex;
	vector<vector<float>> shape = {
		{50.f, 50.f},{0.f, 50.f},{0.f, 100.f},{100.f, 100.f},{100.f, 0.f},{50.f, 0.f}
	};
public:
	Truck();
	Truck(float, float);
	void Move(float, float);
	void Disapear(sf::RenderWindow&);
	void Draw(sf::RenderWindow &);
};

class Car : public Vehicle {

public:
	void Move(int _x, int _y);
};

#endif