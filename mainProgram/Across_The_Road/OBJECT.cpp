#include "OBJECT.h"

COBJECT::COBJECT() {
	mX = 0;
	mY = 0;
}
COBJECT::COBJECT(float x, float y) {
	mX = x;
	mY = y;
}

void COBJECT::Move(float _x, float _y) {
	convex.move(_x, _y);
}

void COBJECT::KeyBoardMove(float _x, float _y) {
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

void COBJECT::Draw(sf::RenderWindow& window) {
	convex.setPointCount(shape.size());
	for (int i = 0; i < shape.size(); i++) {
		convex.setPoint(i, sf::Vector2f(X() + shape[i][0], Y() + shape[i][1]));
	}
	window.draw(convex);
}

void COBJECT::setShape(vector<vector<float>> S) {
	shape = S;
}

float COBJECT::X() {
	return mX;
}
float COBJECT::Y() {
	return mY;
}
void COBJECT::X(float x) {
	mX = x;
}
void COBJECT::Y(float y) {
	mY = y;
}

//CVEHICLE
CVEHICLE::CVEHICLE()
	:COBJECT() {}
CVEHICLE::CVEHICLE(float x, float y)
	: COBJECT(x, y) {}

//CTRUCK
CTRUCK::CTRUCK()
	: CVEHICLE()
{
	setShape({
		{40.f, 40.f},{0.f, 40.f},{0.f, 80.f},{150.f, 80.f},{150.f, 0.f},{40.f, 0.f}
		});
}
CTRUCK::CTRUCK(float x, float y)
	:CVEHICLE(x, y)
{
	setShape({
		{40.f, 40.f},{0.f, 40.f},{0.f, 80.f},{150.f, 80.f},{150.f, 0.f},{40.f, 0.f}
		});
}

//CCAR
CCAR::CCAR()
	: CVEHICLE()
{
	setShape({
		{15.f, 30.f}, { 0.f, 30.f }, { 0.f, 55.f }, { 100.f, 55.f }, { 100.f, 30.f }, { 85.f, 30.f }, { 70.f, 0.f }, { 25.f, 0.f }
		});
}
CCAR::CCAR(float _x, float _y)
	: CVEHICLE(_x, _y)
{
	setShape({
	{15.f, 30.f}, { 0.f, 30.f }, { 0.f, 55.f }, { 100.f, 55.f }, { 100.f, 30.f }, { 85.f, 30.f }, { 70.f, 0.f }, { 25.f, 0.f }
		});
}

//CANIMAL
CANIMAL::CANIMAL()
	: COBJECT() {}
CANIMAL::CANIMAL(float _x, float _y)
	: COBJECT(_x, _y){}

	//CDINOSAUR
CDINOSAUR::CDINOSAUR()
	: CANIMAL()
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

	//CBIRD
CBIRD::CBIRD()
	: CANIMAL()
{
	setShape({
		{2,0}, {4.5, 1}, {6, 2}, {10, 2.5}, {6,13}, {5,17}, {8,22}, {14,18}, {12,13}, {18,10}, {16, 3},{19,3}, {22,2}, {29, 7}, {32,9},{30,2}, {34, 0},
		{30,-2},{32,-9},{29, -7},{22,-2},{19,-3},{16, -3},{18,-10},{12,-13},{14,-18},{8,-22},{5,-17},{6,-13},{10, -2.5},{6, -2},{4.5, -1}
		});
}
CBIRD::CBIRD(float _x, float _y)
	: CANIMAL(_x, _y)
{
	setShape({
		{2,0}, {4.5, 1}, {6, 2}, {10, 2.5}, {6,13}, {5,17}, {8,22}, {14,18}, {12,13}, {18,10}, {16, 3},{19,3}, {22,2}, {29, 7}, {32,9},{30,2}, {34, 0},
		{30,-2},{32,-9},{29, -7},{22,-2},{19,-3},{16, -3},{18,-10},{12,-13},{14,-18},{8,-22},{5,-17},{6,-13},{10, -2.5},{6, -2},{4.5, -1}
		});
}