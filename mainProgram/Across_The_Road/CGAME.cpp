#include "CGAME.h"

void CGAME::initWindow()
{
	settings.antialiasingLevel = 8;
	videoMode = sf::VideoMode(800, 600);
	window = new sf::RenderWindow(videoMode, "Across The Road", sf::Style::Default, settings);

    this->window->setFramerateLimit(60);//not understand

    
}

void CGAME::initObject()
{
    this->people = PEOPLE(400, 600);
}

void CGAME::initEnemies() {};

void CGAME::initLines() {
    this->line = new CLINE[5];
    this->line[0] = CLINE(0.f, 100.f);
    this->line[1] = CLINE(0.f, 200.f);
    this->line[2] = CLINE(0.f, 300.f);
    this->line[3] = CLINE(0.f, 400.f);
    this->line[4] = CLINE(0.f, 500.f);
}

void CGAME::initLevel() {
    MAX_LEVEL = 3;

    setLevel(1);
}


CGAME::CGAME()
{
	initWindow();
    initObject();
    initEnemies();
    initLines();
    initLevel();
}

CGAME::~CGAME()
{
	delete this->window;
    for (int i = 0; i < enemies.size(); i++)
        delete enemies[i];
    delete[] line;
}

const bool CGAME::running() const
{
	return this->window->isOpen();
}

void CGAME::setLevel(unsigned level){
    /*if (level > MAX_LEVEL)
        return;*/
    currentLevel = level;

    //this->points = 0;
    this->enemySpawnTimerMax = (140.f - static_cast<float>((level-1)*40));
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;// loop some   times
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
        e->Move((3.f+static_cast<float>(currentLevel-1)),0.f);
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

    for (int i = 0; i < 5; i++)
        line[i].Draw(*this->window);

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

