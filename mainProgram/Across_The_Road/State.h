#pragma once
#include "includePath.h"
#include "OBJECT.h"

class State
{
private:
	vector<sf::Texture> textures;
	bool quit;
protected:
	sf::RenderWindow* window;
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void endState() = 0;
	const bool& getQuit() const;
	virtual void checkForQuit();

	//update & render
	virtual void update() = 0;
	virtual void render(sf::Event ev, sf::RenderTarget* target = nullptr) = 0;
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
	GameState(sf::RenderWindow* window);
	~GameState();

	void endState();
	void setLevel(unsigned);
	void spawnEnemy();
	void generateMap();
	//Function
	
	//Update & Render
	void updateEnemies();
	void renderEnemies();
	void updatePlayer();
	void renderPlayer(sf::Event);
	void update();
	void render(sf::Event, sf::RenderTarget* target = nullptr);
};