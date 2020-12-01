#include "OBJECT.h"

OBJECT::OBJECT() {
	mX = 0;
	mY = 0;
}
OBJECT::OBJECT(float x, float y) {
	mX = x;
	mY = y;
}

void OBJECT::Move(float _x, float _y) {
	convex.move(_x, _y);
}

void OBJECT::KeyBoardMove(float _x, float _y) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		Move(_x, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		Move(-_x, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		Move(0, _y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		Move(0, -_y);
	}
}

void OBJECT::Draw(sf::RenderWindow& window) {
	convex.setPointCount(shape.size());
	for (int i = 0; i < shape.size(); i++) {
		convex.setPoint(i, sf::Vector2f(X() + shape[i][0], Y() + shape[i][1]));
	}
	window.draw(convex);
}

void OBJECT::setShape(vector<vector<float>> S) {
	shape = S;
}

float OBJECT::X() {
	return mX;
}
float OBJECT::Y() {
	return mY;
}
void OBJECT::X(float x) {
	mX = x;
}
void OBJECT::Y(float y) {
	mY = y;
}

//Vehicle
Vehicle::Vehicle()
	:OBJECT() {}
Vehicle::Vehicle(float x, float y)
	: OBJECT(x, y) {}

	//Truck
Truck::Truck()
	: Vehicle()
{
	setShape({
		{40.f, 40.f},{0.f, 40.f},{0.f, 80.f},{150.f, 80.f},{150.f, 0.f},{40.f, 0.f}
		});
}
Truck::Truck(float x, float y)
	:Vehicle(x, y)
{
	setShape({
		{40.f, 40.f},{0.f, 40.f},{0.f, 80.f},{150.f, 80.f},{150.f, 0.f},{40.f, 0.f}
		});
}

	//Car
Car::Car()
	: Vehicle()
{
	setShape({
		{15.f, 30.f}, { 0.f, 30.f }, { 0.f, 55.f }, { 100.f, 55.f }, { 100.f, 30.f }, { 85.f, 30.f }, { 70.f, 0.f }, { 25.f, 0.f }
		});
}
Car::Car(float _x, float _y)
	: Vehicle(_x, _y)
{
	setShape({
	{15.f, 30.f}, { 0.f, 30.f }, { 0.f, 55.f }, { 100.f, 55.f }, { 100.f, 30.f }, { 85.f, 30.f }, { 70.f, 0.f }, { 25.f, 0.f }
		});
}

//CANIMAL
CANIMAL::CANIMAL()
	: OBJECT() {}
CANIMAL::CANIMAL(float _x, float _y)
	: OBJECT(_x, _y){}

	//CDINOSAUR
CDINOSAUR::CDINOSAUR()
	: CANIMAL()
{

}
CDINOSAUR::CDINOSAUR(float _x, float _y)
	: CANIMAL(_x, _y)
{
	setShape({
		//tail
		{32.f, 50.f}, {28.f, 47.f}, {0.f, 42.f}, { 0.f, 39.f }, { 31.f, 30.f },
		//back
		{61.f, 0.f}, 
		//head
		{80.f, -5.f} , {100.f, 0.f}, {103.f, 6.f}, {100.f, 15.f}, {80.f, 23.f}, {95.f, 29.f},
		{94.f, 32.f}, {75.f, 34.f}, { 61.f, 32.f },
		//hand
		{ 61.f, 40.f }, { 68.f, 50.f }, { 64.f, 55.f }, { 58.f, 49.f }, {57.f, 53.f},
		//leg
		{ 55.f, 71.f }, { 50.f, 71.f }, { 39.f, 40.f }, { 42.f, 71.f }, { 37.f, 71.f }
		});
}