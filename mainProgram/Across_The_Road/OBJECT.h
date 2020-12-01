#pragma once
#include "includePath.h"

class COBJECT
{
private:
	float mX, mY;
	sf::ConvexShape convex;
	vector<vector<float>> shape;
public:
	//Constructor
	COBJECT();
	COBJECT(float, float);

	float X();
	float Y();
	void X(float);
	void Y(float);
	void setShape(vector<vector<float>>);
	virtual void Move(float, float);
	virtual void KeyBoardMove(float, float);
	virtual void Draw(sf::RenderWindow&);
};

class CVEHICLE : public COBJECT {
private:

public:
	CVEHICLE();
	CVEHICLE(float, float);
};

class CTRUCK : public CVEHICLE {
private:

public:
	CTRUCK();
	CTRUCK(float, float);
};

class CCAR : public CVEHICLE {
private:

public:
	CCAR();
	CCAR(float, float);
};

class CANIMAL : public COBJECT {
private:

public:
	CANIMAL();
	CANIMAL(float, float);
	//virtual void Tell();
};

class CDINAUSOR : public CANIMAL {
public:
	CDINAUSOR();
	CDINAUSOR(float, float);
};

class CBIRD : public CANIMAL {
public:
	CBIRD();
	CBIRD(float, float);
};
