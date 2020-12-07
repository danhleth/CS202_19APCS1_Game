#include "CGAME.h"

void CGAME::initWindow()
{
	settings.antialiasingLevel = 8;
	videoMode = sf::VideoMode(800, 600);
	window = new sf::RenderWindow(videoMode, "Across The Road", sf::Style::Default, settings);

    this->window->setFramerateLimit(60);//not understand

    this->points = 0;
    this->enemySpawnTimerMax = 120.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 7;
}

void CGAME::initObject()
{
    this->people = PEOPLE(400, 600);
}

void CGAME::initEnemies() {};

CGAME::CGAME()
{
	initWindow();
    initObject();
    initEnemies();
}

CGAME::~CGAME()
{
	delete this->window;
    for (int i = 0; i < enemies.size(); i++)
        delete enemies[i];
}

const bool CGAME::running() const
{
	return this->window->isOpen();
}
   
void CGAME::updateEnemies(){
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
        e->Move(2.f,0.f);
}

void CGAME::renderEnemies(){
    for (auto& e : this->enemies)
        e->Draw(*this->window);
}

void CGAME::spawnEnemy() {
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
    this->enemy->setPosition(0.f,tmpp);

    this->enemies.push_back(enemy);
}

void CGAME::pollEvent()
{
    while (this->window->pollEvent(this->event)) {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            break;
        default:
            break;
        }
    }
}

void CGAME::update()
{
    this->pollEvent();
    this->updateEnemies();
}

void CGAME::render()
{
    this->window->clear(/*sf::Color(255, 255, 255, 0)*/);
    //Draw game
    people.Draw(*this->window);
    people.KeyBoardMove(1.f, 0.5f);
    renderEnemies();

    this->window->display();
}

