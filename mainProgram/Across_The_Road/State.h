#pragma once
#include "includePath.h"
#include "OBJECT.h"

class State
{
private:
	vector<sf::Texture> textures;
	bool quit;
	bool goNext;
protected:
	sf::RenderWindow* window;
	stack<State*>* states;
public:
	State(sf::RenderWindow* window, stack<State*>*);
	virtual ~State();

	virtual void endState() = 0;
	const bool& getQuit() const;
	virtual void setQuit(bool);
	virtual void checkForQuit();

	//update & render
	virtual void update() = 0;
	virtual void render(sf::Event, sf::RenderTarget* target = nullptr) = 0;
};

class GameState : public State {
private:
	//Logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned maxEnemies;
	float enemyEndTimer;
	float enemyEndTimerMax;
	//Objects
	PEOPLE people;
	COBJECT* enemy;
	vector<COBJECT*> enemies;
	COBJECT* line;
	//Level
	int currentLevel;
	int MAX_LEVEL;
	//Init
	void initPlayer();
	void initEnemies();
	void initLines();
	void initLevel();
public:
	GameState(sf::RenderWindow* window, stack<State*>*);
	~GameState();
	
	void endState();
	void setLevel(unsigned);
	void spawnEnemy();
	void generateMap();
	//Function
	
	//Update & Render
	void updateEnemies();
	void renderEnemies();
	void renderPlayer(sf::Event);
	void update();
	void render(sf::Event, sf::RenderTarget* target = nullptr);
};

class MenuState : public State {
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::RectangleShape rec[3];
	sf::Text text[3];
	sf::Font font;
	int currentButton;
	bool ismoving;

	void initFont();
	void initButton();
	void initBackground();
public:
	MenuState(sf::RenderWindow* window, stack<State*>*);
	~MenuState();
	//Function
	void endState();
	void nextButton(sf::Event);
	void highlight();
	void checkButton();
	//Update & Render

	void update();
	void render(sf::Event, sf::RenderTarget* target = nullptr);
};