#include "State.h"

State::State(sf::RenderWindow* window)
{
	this->window = window;
	this->quit = false;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}
void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->quit = true;
	}
}

GameState::GameState(sf::RenderWindow* window) :
	State(window)
{
    initPlayer();
    initEnemies();
    initLines();
    initLevel();
}

GameState::~GameState()
{
    delete this->window;
    for (int i = 0; i < enemies.size(); i++)
        delete enemies[i];
    delete[] line;
}

void GameState::endState()
{
	cout << "End GameState" << endl;
}

void GameState::update()
{
    this->updateEnemies();
    this->updatePlayer();
}

void GameState::render(sf::RenderTarget* target)
{
    renderPlayer();
    renderEnemies();
    generateMap();
}

void GameState::initPlayer()
{
	this->people = PEOPLE(400, 600);
}

void GameState::initEnemies() {}

void GameState::initLines() {
	this->line = new CLINE[5];
	this->line[0] = CLINE(0.f, 100.f);
	this->line[1] = CLINE(0.f, 200.f);
	this->line[2] = CLINE(0.f, 300.f);
	this->line[3] = CLINE(0.f, 400.f);
	this->line[4] = CLINE(0.f, 500.f);
}

void GameState::initLevel() {
	MAX_LEVEL = 3;

	setLevel(1);
}

void GameState::setLevel(unsigned level) {
    /*if (level > MAX_LEVEL)
        return;*/
    currentLevel = level;

    //this->points = 0;
    this->enemySpawnTimerMax = (140.f - static_cast<float>((level - 1) * 40));
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;// loop some   times
}

void GameState::updateEnemies() {
    //to create the enemies
    if (this->enemies.size() < this->maxEnemies) {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            //spaw the enemy and reset the timer
            this->spawnEnemy();
            enemySpawnTimer = 0.f;
        }
        else
            enemySpawnTimer += 1.f;
    }
    else {
        enemies.erase(enemies.begin());// 6 = max - 1
    }
    for (auto& e : this->enemies)
        e->Move((3.f + static_cast<float>(currentLevel - 1)), 0.f);
}

void GameState::renderEnemies() {
    for (auto& e : this->enemies)
        e->Draw(this->window);
}

void GameState::updatePlayer()
{
    this->people.KeyBoardMove(1.f, 1.f);
}

void GameState::renderPlayer()
{
    this->people.Draw(this->window);
}

void GameState::spawnEnemy() {
    unsigned tmp = static_cast<unsigned>(rand() % 4);
    switch (tmp)
    {
    case 0:
        this->enemy = new CTRUCK;
        break;
    case 1:
        this->enemy = new CCAR;
        break;
    case 2:
        this->enemy = new CBIRD;
        break;
    default:
        this->enemy = new CDINOSAUR;
        break;
    }
    float tmpp = 200 + static_cast<float>((rand() % 4) * 100);
    this->enemy->setPosition(0.f, tmpp);

    this->enemies.push_back(enemy);
}

void GameState::generateMap()
{
    for (int i = 0; i < 5; i++)
        line[i].Draw(this->window);

    this->window->display();

    if (people.getY() <= 100.f) {
        if (currentLevel >= 3)
            setLevel(1);
        else {
            ++currentLevel;
            setLevel(currentLevel);
        }
        people.setPosition(400, 600);
        enemies.clear();
    }
}

