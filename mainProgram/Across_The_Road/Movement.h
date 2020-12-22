#pragma once
#include "includePath.h"

class Movement
{
private:
	float maxVeclocity;
	sf::Vector2f veclocity, acceleration, decceleration;
public:
	//Constructor - Destructor
	Movement(float maxVeclocity);
	~Movement();

	//Fucntions
	const sf::Vector2f getVeclocity();
	void move(const float x, const float y);

	//Update & Render
	void update();

};

