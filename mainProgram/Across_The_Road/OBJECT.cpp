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
	if(typeid(*this) != typeid(PEOPLE))
		convex.setFillColor(sf::Color::Green);
	for (int i = 0; i < shape.size(); i++) {
		convex.setPoint(i, sf::Vector2f(X() + shape[i][0], Y() + shape[i][1]));
	}
	window.draw(convex);
}

void COBJECT::setPosition(float x, float y) {
	mX = x;
	mY = y;
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
		{0.f ,0.f}, {0.f, -100.f}, {115.f, -100.f}, {115.f, -45.f}, {120.f, -70.f}, {150.f, -70.f}, { 170.f, -35.f }, { 175.f, -35.f }, { 180.f, -30.f }, { 180.f, 0.f }
		});
}
CTRUCK::CTRUCK(float x, float y)
	:CVEHICLE(x, y)
{
	setShape({
		{0.f ,0.f}, {0.f, -100.f}, {115.f, -100.f}, {115.f, -45.f}, {120.f, -70.f}, {150.f, -70.f}, { 170.f, -35.f }, { 175.f, -35.f }, { 180.f, -30.f }, { 180.f, 0.f }
		});
}

//CCAR
CCAR::CCAR()
	: CVEHICLE()
{
	setShape({
		{0.f, 0.f}, {90.f, 0.f}, {90.f, -7.f}, {88.f, -12.f}, {82.f, -12.f}, {68.f, -36.f}, {18.f, -36.f}, {10.f, -12.f}, {0.f, -12.f}
		});
}
CCAR::CCAR(float _x, float _y)
	: CVEHICLE(_x, _y)
{
	setShape({
		{0.f, 0.f}, {90.f, 0.f}, {90.f, -7.f}, {88.f, -12.f}, {82.f, -12.f}, {68.f, -36.f}, {18.f, -36.f}, {10.f, -12.f}, {0.f, -12.f}
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
		{32.f, -21.f}, {28.f, -24.f}, {0.f, -29.f}, { 0.f, -32.f }, { 31.f, -41.f },
		//back
		{61.f, -71.f},
		//head
		{80.f, -76.f} , {100.f, -71.f}, {103.f, -66.f}, {100.f, -56.f}, {80.f, -48.f}, {95.f, -42.f},
		{94.f, -39.f}, {75.f, -37.f}, { 61.f, -39.f },
		//hand
		{ 61.f, -31.f }, { 68.f, -21.f }, { 64.f, -16.f }, { 58.f, -22.f }, {57.f, -18.f},
		//leg
		{ 55.f, 0.f }, { 50.f, 0.f }, { 39.f, -31.f }, { 42.f, 0.f }, { 37.f, 0.f }
		});
}
CDINOSAUR::CDINOSAUR(float _x, float _y)
	: CANIMAL(_x, _y)
{
	setShape({
		//tail
		{32.f, -21.f}, {28.f, -24.f}, {0.f, -29.f}, { 0.f, -32.f }, { 31.f, -41.f },
		//back
		{61.f, -71.f}, 
		//head
		{80.f, -76.f} , {100.f, -71.f}, {103.f, -66.f}, {100.f, -56.f}, {80.f, -48.f}, {95.f, -42.f},
		{94.f, -39.f}, {75.f, -37.f}, { 61.f, -39.f },
		//hand
		{ 61.f, -31.f }, { 68.f, -21.f }, { 64.f, -16.f }, { 58.f, -22.f }, {57.f, -18.f},
		//leg
		{ 55.f, 0.f }, { 50.f, 0.f }, { 39.f, -31.f }, { 42.f, 0.f }, { 37.f, 0.f }
		});
}

	//CBIRD
CBIRD::CBIRD()
	: CANIMAL()
{
	setShape({
		{-2,-22}, {-4.5, -21}, {-6, -19}, {-10, -19.5}, {-6, -9}, {-5,-5}, {-8,0}, {-14,-4}, {-12,-9}, {-18,-12}, {-16, -19},{-19,-19}, {-22,-20}, {-29, -15}, {-32,-13},{-30,-20}, {-34, -20},
		{-30,-24},{-32,-31},{-29, -29},{-22,-24},{-19,-25},{-16, -25},{-18,-32},{-12,-35},{-14,-40},{-8,-44},{-5,-39},{-6,-35},{-10, -24.5},{-6, -24},{-4.5, -23}
		});
}
CBIRD::CBIRD(float _x, float _y)
	: CANIMAL(_x, _y)
{
	setShape({
		{-2,-22}, {-4.5, -21}, {-6, -19}, {-10, -19.5}, {-6, -9}, {-5,-5}, {-8,0}, {-14,-4}, {-12,-9}, {-18,-12}, {-16, -19},{-19,-19}, {-22,-20}, {-29, -15}, {-32,-13},{-30,-20}, {-34, -20},
		{-30,-24},{-32,-31},{-29, -29},{-22,-24},{-19,-25},{-16, -25},{-18,-32},{-12,-35},{-14,-40},{-8,-44},{-5,-39},{-6,-35},{-10, -24.5},{-6, -24},{-4.5, -23}
		});
}

//PEOPLE
PEOPLE::PEOPLE() : COBJECT(){
	mState = 1;
	setShape({
		{0, -55}, {-4, -54}, {-9, -52}, { -13, -47 }, {-15, -42},{ -15.5, -37.9 }, {-13, -33}, { -11, -31 },/* {-16.6, -33.4},*/{ -8.3, -29 }, { -16.6, -20 }, { -12.5, -15 }, { -8.5, -18 }, { -12, 0 }, { -4, 0 }, { -2, -8 },
		{2, -8},{4, 0},{12, 0}, {8.5, -18},{12.5, -15},  {15, -20},{8.3, -29},{11, -31},{13, -33},{ 15.5, -37.9 }, {15, -42}, {13, -47 }, {9, -52}, {4, -54}
		});
}
PEOPLE::PEOPLE(float _x, float _y) : COBJECT(_x, _y) {
	mState = 1;
	setShape({
		{0, -55}, {-4, -54}, {-9, -52}, { -13, -47 }, {-15, -42},{ -15.5, -37.9 }, {-13, -33}, { -11, -31 },/* {-16.6, -33.4},*/{ -8.3, -29 }, { -16.6, -20 }, { -12.5, -15 }, { -8.5, -18 }, { -12, 0 }, { -4, 0 }, { -2, -8 },
		{2, -8},{4, 0},{12, 0}, {8.5, -18},{12.5, -15},  {15, -20},{8.3, -29},{11, -31},{13, -33},{ 15.5, -37.9 }, {15, -42}, {13, -47 }, {9, -52}, {4, -54}
		});
}
