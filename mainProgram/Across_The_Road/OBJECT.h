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
	float getX();
	float getY();
	void changeConvex(sf::ConvexShape _convex);
	sf::ConvexShape getConvex();
	void setShape(vector<vector<float>>);
	virtual void Move(float, float);
	virtual void KeyBoardMove(float, float);
	virtual void Draw(sf::RenderTarget*);
	virtual void setPosition(float, float);
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


class PEOPLE : public COBJECT{
private:
	float speed=1.f;
	bool mState;
public:
	PEOPLE();
	PEOPLE(float, float);
	void KeyBoadMove_WithDt(float);
	void setSpeed(float);
	bool isImpact(const CVEHICLE*);
	bool isImpact(const CANIMAL*);
	bool isFinish();
	bool isDead();
	void collisionAnimation(const CVEHICLE*);
	void collisionAnimation(const CANIMAL*);
};

class CLINE : public COBJECT {
public:
	CLINE();
	CLINE(float,float);
};