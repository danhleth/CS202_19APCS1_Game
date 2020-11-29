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
	virtual void Move(float, float);
};

class Truck : public Vehicle {
private:
	sf::ConvexShape convex;
	vector<vector<float>> shape = {
		{40.f, 40.f},{0.f, 40.f},{0.f, 80.f},{150.f, 80.f},{150.f, 0.f},{40.f, 0.f}
	};
public:
	Truck();
	Truck(float, float);
	void Move(float, float);
	void Disappear(sf::RenderWindow&);
	void Draw(sf::RenderWindow &);
};

class Car : public Vehicle {
private:
	sf::ConvexShape convex;
	vector<vector<float>> shape = {
		{15.f, 30.f},{0.f, 30.f},{0.f, 55.f},{100.f, 55.f},{100.f, 30.f},{85.f, 30.f}, {70.f, 0.f}, {25.f, 0.f}
	};
public:
	Car();
	Car(float, float);
	void Move(float, float);
	void Disappear(sf::RenderWindow&);
	void Draw(sf::RenderWindow&);
};

#endif