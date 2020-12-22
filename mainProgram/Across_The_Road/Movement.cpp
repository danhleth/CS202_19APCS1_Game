#include "Movement.h"

//Constructor - Destructor
Movement::Movement(float maxVeclocity)
{
	this->maxVeclocity = maxVeclocity;
}

Movement::~Movement()
{
}

const sf::Vector2f Movement::getVeclocity()
{
	return this->veclocity;
}

//Fucntions
void Movement::move(const float x, const float y)
{
	this->veclocity.x = this->maxVeclocity * x;
	this->veclocity.y = this->maxVeclocity * y;
}

//Update & Render
void Movement::update()
{
}
