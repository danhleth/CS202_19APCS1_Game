#pragma once
#include "includePath.h"

class CGAME
{
private:
	sf::RenderWindow* window;
	sf::ContextSettings settings;
	sf::VideoMode videoMode;
	sf::Event event;
	//Logic
	//int points;
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
	void initWindow();
	void initObject();
	void initEnemies();
	void initLines();
	void initLevel();
public:
	//Constructors & Destructors
	CGAME();
	~CGAME();
	//Accessors
	const bool running() const;
	void setLevel(unsigned);
	void updateEnemies();
	void renderEnemies();
	void spawnEnemy();
	//Function
	void pollEvent();
	//Update & Render
	void update();
	void render();
};