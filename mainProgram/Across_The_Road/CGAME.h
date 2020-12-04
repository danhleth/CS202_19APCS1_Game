#pragma once
#include "includePath.h"

class CGAME
{
private:
	sf::RenderWindow* window;
	sf::ContextSettings settings;
	sf::VideoMode videoMode;
	sf::Event event;
	//Objects
	PEOPLE people;
	//InitWindow
	void initWindow();
	void initObject();
public:
	//Constructors & Destructors
	CGAME();
	~CGAME();
	//Accessors
	const bool running() const;

	//Function
	void pollEvent();
	//Update & Render
	void update();
	void render();
};