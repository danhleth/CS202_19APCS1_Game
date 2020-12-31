#include "OBJECT.h"

COBJECT::COBJECT() {
	mX = 0;
	mY = 0;
	this->texture = NULL;
	this->sprite = NULL;
	this->movement = NULL;
	this->createMovement(3);
}

COBJECT::COBJECT(float x, float y) {
	mX = x;
	mY = y;
	this->texture = NULL;
	this->sprite = NULL;
	this->createMovement(3);
}

void COBJECT::update()
{
	int a = 0;
}

COBJECT::COBJECT(sf::Texture* texture) {
	mX = 0;
	mY = 0;
	this->texture = NULL;
	this->sprite = NULL;
	this->movement = NULL;
	createSprite(texture);
	this->createMovement(3);
}
COBJECT::COBJECT(float x, float y, sf::Texture* texture) {
	mX = x;
	mY = y;
	this->texture = NULL;
	this->sprite = NULL;
	createSprite(texture);
	this->createMovement(3);
}

void COBJECT::createSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}

void COBJECT::createMovement(float maxVeclocity) {
	this->movement = new Movement(maxVeclocity);
}

void COBJECT::Move(float _x, float _y) {
	this->movement->move(_x, _y);
	this->sprite->move(this->movement->getVeclocity());
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

void COBJECT::Draw(sf::RenderTarget* window) {
	//convex.setPointCount(shape.size());
	//if(typeid(*this) != typeid(PEOPLE)&& typeid(*this) != typeid(CLINE))
	//	convex.setFillColor(sf::Color::Green);
	//for (int i = 0; i < shape.size(); i++) {
	//	convex.setPoint(i, sf::Vector2f(X() + shape[i][0], Y() + shape[i][1]));
	//}
	//window->draw(convex);
	window->draw(*this->sprite);
}

void COBJECT::setPosition(float x, float y) {
	mX = x;
	mY = y;
	this->sprite->setPosition(x, y);
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

float COBJECT::getX(){
	return static_cast<float>(sprite->getPosition().x)+mX;
}

float COBJECT::getY(){
	return static_cast<float>(sprite->getPosition().y)+mY;
}

void COBJECT::createAnimation(sf::Texture& texture)
{
	this->animation = new AnimationComponent(texture, *this->sprite);
}

void COBJECT::changeConvex(sf::ConvexShape _convex)
{
	this->convex = _convex;
}

sf::ConvexShape COBJECT::getConvex()
{
	return this->convex;
}

//CVEHICLE
CVEHICLE::CVEHICLE(sf::Texture* texture)
	:COBJECT(texture) {}
CVEHICLE::CVEHICLE(float x, float y, sf::Texture* texture)
	: COBJECT(x, y,texture) {}

//CTRUCK
CTRUCK::CTRUCK(sf::Texture* texture)
	: CVEHICLE(texture)
{
	//setShape({
	//	{0.f ,0.f}, {0.f, -80.f}, {115.f, -80.f}, {115.f, -45.f}, {120.f, -70.f}, {150.f, -70.f}, { 170.f, -35.f }, { 175.f, -35.f }, { 180.f, -30.f }, { 180.f, 0.f }
	//	});

}
//CTRUCK::CTRUCK(float x, float y)
//	:CVEHICLE(x, y)
//{
//	setShape({
//		{0.f ,0.f}, {0.f, -80.f}, {115.f, -80.f}, {115.f, -45.f}, {120.f, -70.f}, {150.f, -70.f}, { 170.f, -35.f }, { 175.f, -35.f }, { 180.f, -30.f }, { 180.f, 0.f }
//		});
//}

//CCAR
CCAR::CCAR(sf::Texture* texture)
	: CVEHICLE(texture)
{
	//setShape({
	//	{0.f, 0.f}, {90.f, 0.f}, {90.f, -7.f}, {88.f, -12.f}, {82.f, -12.f}, {68.f, -36.f}, {18.f, -36.f}, {10.f, -12.f}, {0.f, -12.f}
	//	});
	this->sprite->setScale(0.2f, 0.2f);
}
//CCAR::CCAR(float _x, float _y)
//	: CVEHICLE(_x, _y)
//{
//	setShape({
//		{0.f, 0.f}, {90.f, 0.f}, {90.f, -7.f}, {88.f, -12.f}, {82.f, -12.f}, {68.f, -36.f}, {18.f, -36.f}, {10.f, -12.f}, {0.f, -12.f}
//		});
//}

//CANIMAL
CANIMAL::CANIMAL(sf::Texture* texture)
	: COBJECT(texture) {}
CANIMAL::CANIMAL(float _x, float _y)
	: COBJECT(_x, _y){}

	//CDINOSAUR
CDINOSAUR::CDINOSAUR(sf::Texture* texture)
	: CANIMAL(texture)
{
	//setShape({
	//	//tail
	//	{32.f, -21.f}, {28.f, -24.f}, {0.f, -29.f}, { 0.f, -32.f }, { 31.f, -41.f },
	//	//back
	//	{61.f, -71.f},
	//	//head
	//	{80.f, -76.f} , {100.f, -71.f}, {103.f, -66.f}, {100.f, -56.f}, {80.f, -48.f}, {95.f, -42.f},
	//	{94.f, -39.f}, {75.f, -37.f}, { 61.f, -39.f },
	//	//hand
	//	{ 61.f, -31.f }, { 68.f, -21.f }, { 64.f, -16.f }, { 58.f, -22.f }, {57.f, -18.f},
	//	//leg
	//	{ 55.f, 0.f }, { 50.f, 0.f }, { 39.f, -31.f }, { 42.f, 0.f }, { 37.f, 0.f }
	//	});
	this->sprite->setScale(1.3f, 1.3f);
	this->createAnimation(*texture);
	this->animation->addAnimation("LEFT", 60.f, 0, 0, 11, 0, 54, 50);
}

//CDINOSAUR::CDINOSAUR(float _x, float _y)
//	: CANIMAL(_x, _y)
//{
//	setShape({
//		//tail
//		{32.f, -21.f}, {28.f, -24.f}, {0.f, -29.f}, { 0.f, -32.f }, { 31.f, -41.f },
//		//back
//		{61.f, -71.f}, 
//		//head
//		{80.f, -76.f} , {100.f, -71.f}, {103.f, -66.f}, {100.f, -56.f}, {80.f, -48.f}, {95.f, -42.f},
//		{94.f, -39.f}, {75.f, -37.f}, { 61.f, -39.f },
//		//hand
//		{ 61.f, -31.f }, { 68.f, -21.f }, { 64.f, -16.f }, { 58.f, -22.f }, {57.f, -18.f},
//		//leg
//		{ 55.f, 0.f }, { 50.f, 0.f }, { 39.f, -31.f }, { 42.f, 0.f }, { 37.f, 0.f }
//		});
//}

void CDINOSAUR::update() {
	this->animation->play("LEFT");
}

	//CBIRD
CBIRD::CBIRD(sf::Texture* texture)
	: CANIMAL(texture)
{
	//setShape({
	//	{-2,-22}, {-4.5, -21}, {-6, -19}, {-10, -19.5}, {-6, -9}, {-5,-5}, {-8,0}, {-14,-4}, {-12,-9}, {-18,-12}, {-16, -19},{-19,-19}, {-22,-20}, {-29, -15}, {-32,-13},{-30,-20}, {-34, -20},
	//	{-30,-24},{-32,-31},{-29, -29},{-22,-24},{-19,-25},{-16, -25},{-18,-32},{-12,-35},{-14,-40},{-8,-44},{-5,-39},{-6,-35},{-10, -24.5},{-6, -24},{-4.5, -23}
	//	});
	this->sprite->setScale(0.5f, 0.5f);
	this->createAnimation(*texture);
	this->animation->addAnimation("LEFT", 60.f, 0, 0, 8, 0, 160, 173);

}
CBIRD::CBIRD(float _x, float _y)
	: CANIMAL(_x, _y)
{
	setShape({
		{-2,-22}, {-4.5, -21}, {-6, -19}, {-10, -19.5}, {-6, -9}, {-5,-5}, {-8,0}, {-14,-4}, {-12,-9}, {-18,-12}, {-16, -19},{-19,-19}, {-22,-20}, {-29, -15}, {-32,-13},{-30,-20}, {-34, -20},
		{-30,-24},{-32,-31},{-29, -29},{-22,-24},{-19,-25},{-16, -25},{-18,-32},{-12,-35},{-14,-40},{-8,-44},{-5,-39},{-6,-35},{-10, -24.5},{-6, -24},{-4.5, -23}
		});
}

void CBIRD::update() {
	this->animation->play("LEFT");
}

//PEOPLE
PEOPLE::PEOPLE(){
	mState = 1;
	isMoving = false;
	setShape({
		{0, -55}, {-4, -54}, {-9, -52}, { -13, -47 }, {-15, -42},{ -15.5, -37.9 }, {-13, -33}, { -11, -31 },/* {-16.6, -33.4},*/{ -8.3, -29 }, { -16.6, -20 }, { -12.5, -15 }, { -8.5, -18 }, { -12, 0 }, { -4, 0 }, { -2, -8 },
		{2, -8},{4, 0},{12, 0}, {8.5, -18},{12.5, -15},  {15, -20},{8.3, -29},{11, -31},{13, -33},{ 15.5, -37.9 }, {15, -42}, {13, -47 }, {9, -52}, {4, -54}
		});

}



PEOPLE::PEOPLE(float x, float y, sf::Texture* texture) : COBJECT(x, y, texture) {
	mState = 1;
	//setShape({
	//	{0, -55}, {-4, -54}, {-9, -52}, { -13, -47 }, {-15, -42},{ -15.5, -37.9 }, {-13, -33}, { -11, -31 },/* {-16.6, -33.4},*/{ -8.3, -29 }, { -16.6, -20 }, { -12.5, -15 }, { -8.5, -18 }, { -12, 0 }, { -4, 0 }, { -2, -8 },
	//	{2, -8},{4, 0},{12, 0}, {8.5, -18},{12.5, -15},  {15, -20},{8.3, -29},{11, -31},{13, -33},{ 15.5, -37.9 }, {15, -42}, {13, -47 }, {9, -52}, {4, -54}
	//	});
	this->sprite->setPosition(x, y);
	this->sprite->setScale(0.9f, 0.9f);
	this->createAnimation(*texture);
	this->animation->addAnimation("LEFT", 60.f, 0, 0, 2, 0, 50, 61);
}



void PEOPLE::setSpeed(float)
{
}

void PEOPLE::KeyBoadMove_WithDt(float distance, sf::Event &ev) {
	
	if (ev.key.code == sf::Keyboard::D) {
		this->sprite->move(30.f, 0.f);
		isMoving = true;
	}
	if (ev.key.code == sf::Keyboard::A) {
		/*Move(-10.f, 0.f);*/
		this->sprite->move(-30.f, 0.f);
		isMoving = true;
	}
	if (ev.key.code == sf::Keyboard::S) {
		/*Move(0.f, distance);*/
		this->sprite->move(0.f, distance);
		isMoving = true;
	}
	if (ev.key.code == sf::Keyboard::W) {
		/*Move(0.f, -distance);*/
		this->sprite->move(0.f, -distance);
		isMoving = true;
	}
	ev.key.code = sf::Keyboard::Unknown;
}

void PEOPLE::collisionAnimation()
{
	if (this->isImpact()) {
		sf::ConvexShape x = this->getConvex();
		x.setFillColor(sf::Color::Red);
		this->changeConvex(x);
	}
}

void PEOPLE::Draw(sf::RenderTarget* window)
{
	window->draw(*sprite);
}

void PEOPLE::update()
{
	this->animation->play("LEFT");
}
