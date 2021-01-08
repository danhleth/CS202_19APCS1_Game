#pragma once
#include "includePath.h"

class PauseMenu
{
private:
	sf::RenderWindow *window;
	
	sf::RectangleShape background, container;
	sf::RectangleShape rec[3];
	sf::Text text[3];
	sf::Font font;
	int currentButton;
	bool ismoving;
	bool unpause;

	void initFont();
	void initButton();
	void initBackground();
	
public:
	PauseMenu(sf::RenderWindow*);
	~PauseMenu();
	//Function
	void nextButton(sf::Event&);
	void highlight();
	void checkButton(sf::Event &);
	//End Pause
	bool getPause() const;
	void setPause(bool);
	void checkForUnpause();
	void EndPause();
	int senderFromGame;
	//Update & Render
	void update();
	void render(sf::Event &, sf::RenderTarget* target = nullptr);
};

class MessageBox {
private:
	sf::RenderWindow* window;
	sf::RectangleShape box;
	sf::Text text[2];
	sf::Font font;
	int points;
public:
	bool pause;
	MessageBox(sf::RenderWindow*, int);
	void initFont();
	void initBackground();
	void draw(sf::RenderTarget*);
	bool checkQuit(sf::Event&);
	void setPoints(int);
};