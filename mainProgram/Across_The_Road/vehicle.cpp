#include "vehicle.h"

	//Vehicle
Vehicle::Vehicle() {
	mX = 0;
	mY = 0;
}

Vehicle::Vehicle(float x, float y) {
	mX = x;
	mY = y;
}

void Vehicle::Move(float _x, float _y) {

}

float Vehicle::X() {
	return mX;
}
float Vehicle::Y() {
	return mY;
}
void Vehicle::X(float x) {
	mX = x;
}
void Vehicle::Y(float y) {
	mY = y;
}

	//Truck
Truck::Truck() {}
Truck::Truck(float x, float y) 
	:Vehicle(x,y) {}

void Truck::Move(float _x, float _y) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		convex.move(_x, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		convex.move(-_x, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		convex.move(0 , _y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		convex.move(0, -_y);
	}
}

void Truck::Disappear(sf::RenderWindow& window) {
	
}

void Truck::Draw(sf::RenderWindow &window) {
	convex.setPointCount(6);
	for (int i = 0; i < shape.size(); i++) {
		convex.setPoint(i, sf::Vector2f(X()+shape[i][0],Y()+shape[i][1]));
	}
	window.draw(convex);
}

	//Car
void Car::Move(float _x, float _y) {

}