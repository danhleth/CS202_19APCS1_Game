#pragma once
#include "includePath.h"

class OBJECT
{
private:
	float mX, mY;
	sf::ConvexShape convex;
	vector<vector<float>> shape;
public:
	//Constructor
	OBJECT();
	OBJECT(float, float);

	float X();
	float Y();
	void X(float);
	void Y(float);
	void setShape(vector<vector<float>>);
	virtual void Move(float, float);
	virtual void KeyBoardMove(float, float);
	virtual void Draw(sf::RenderWindow&);
};

class Vehicle : public OBJECT {
private:

public:
	Vehicle();
	Vehicle(float, float);
};

class Truck : public Vehicle {
private:

public:
	Truck();
	Truck(float, float);
};

class Car : public Vehicle {
private:

public:
	Car();
	Car(float, float);
};

class CANIMAL : public OBJECT {
private:

public:
	CANIMAL();
	CANIMAL(float, float);
	//virtual void Tell();
};

class CDINOSAUR : public CANIMAL {
public:
	CDINOSAUR();
	CDINOSAUR(float, float);
};

class CBIRD : public CANIMAL {
public:
	CBIRD();
	CBIRD(float, float);
};


class PEOPLE : public OBJECT{
private:
	bool mState;
public:
	PEOPLE();
	PEOPLE(float, float);
	bool isImpact(const Vehicle*&);
	//bool isImpact(const CAnimal)
	bool isFinish();
	bool isDead();
};