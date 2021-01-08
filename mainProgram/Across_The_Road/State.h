#pragma warning(disable : 4996)
#include "includePath.h"
#include "OBJECT.h"
#include "PauseMenu.h"
#define NUMBER_FILE 10
//#include "Sound.h"

class State
{
private:
	bool quit;
protected:
	vector<string> Lfile;
	bool pause;
	sf::RenderWindow* window;
	stack<State*>* states;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
public:
	State(sf::RenderWindow* window, stack<State*>*);
	
	virtual ~State();
	//Pause and Unpause
	void pauseState();
	void unpauseState();

	virtual void endState() = 0;
	const bool& getQuit() const;
	virtual void setQuit(bool);
	virtual void checkForQuit();

	//update & render
	virtual void update() = 0;
	virtual void render(sf::Event &, sf::RenderTarget* target = nullptr) = 0;
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
	//Traffic lights
	vector<COBJECT*> trafficLights;
	int currentTrafficLights;
	float trafficLightsSpawnTimer;
	float trafficLightsSpawnTimerMax;
	//Objects
	PEOPLE people;
	COBJECT* enemy;
	vector<COBJECT*> enemies;
	map<string, sf::SoundBuffer> soundBuffers;
	map<string, sf::Sound> sounds;
	//sf::Music backgroundSound;
	COBJECT* line;
	map<string, sf::Texture> textures;
	//Level
	int currentLevel;
	int MAX_LEVEL;
	//PauseMenu
	PauseMenu *pauseMenu;
	MessageBox* messageBox;
	void checkForPause();
	void checkFromPause();
	//Init
	void initPlayer();
	void initEnemies();
	void initTextures();
	void initBackground();
	void initLevel();
	void initLevel(int);
	void initTrafficLights();
	void initSound();
	void saveFile();
public:
	GameState(sf::RenderWindow* window, stack<State*>*);
	GameState(sf::RenderWindow* window, stack<State*>*, int);
	~GameState();
	//Function
	void endState();
	void setLevel(unsigned);
	void spawnEnemy();
	void generateMap();
	void checkImpact();
	
	//Update & Render
	void updateEnemies();
	void renderEnemies();
	void renderPlayer(sf::Event &);
	void updateTrafficLights();
	void renderTrafficLights();
	void update();
	void render(sf::Event &, sf::RenderTarget* target = nullptr);
};

class LoadFileState : public State {
private:
	sf::RectangleShape rec[NUMBER_FILE];
	sf::Text text[NUMBER_FILE];
	sf::Font font;
	int currentButton;
	bool ismoving;
	void initFont();
	void initButton();
	void initBackground();
	vector<string> getListfromFile();
public:
	LoadFileState(sf::RenderWindow* window, stack<State*>*);
	~LoadFileState();
	//Function
	void endState();
	void nextButton(sf::Event);
	void highlight();
	void checkButton();
	//Update & Render

	void update();
	void render(sf::Event&, sf::RenderTarget* target = nullptr);
};


class MenuState : public State {
	LoadFileState* filebox;
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
	void checkButton(sf::Event &);
	//Update & Render

	void update();
	void render(sf::Event &, sf::RenderTarget* target = nullptr);
};


