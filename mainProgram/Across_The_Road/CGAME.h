#pragma once
#include "includePath.h"
#include "State.h"
class CGAME
{
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::RenderWindow* window;
	sf::ContextSettings settings;
	sf::VideoMode videoMode;
	sf::Event event;
	//States
	stack<State*> states;
	void initStates();
	void initWindow();

	//void initBackground();

public:
	//Constructors & Destructors
	CGAME();
	~CGAME();
	//Accessors
	const bool running() const;
	void pollEvent();
	//Update&Render
	void update();
	void render();

};