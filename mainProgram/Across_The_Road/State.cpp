#include "State.h"

State::State(sf::RenderWindow* window, stack<State*>* states)
{
	this->window = window;
    this->states = states;
	this->quit = false;
    this->pause = false;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::setQuit(bool q)
{
    this->quit = q;
}


void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->quit = true;
	}
}

//Pause and Unpause
void State::pauseState()
{
    this->pause = true;
}

void State::unpauseState()
{
    this->pause = false;
}

//GAMESTATE
GameState::GameState(sf::RenderWindow* window, stack<State*>* states) :
	State(window, states)
{
    initTextures();
    initPlayer();
    initEnemies();
    initBackground();
    initLevel();

    this->pauseMenu = new PauseMenu(this->window);

    this->points = 0;
    this->enemySpawnTimerMax = 120.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 7;
}

GameState::~GameState()
{
    for (int i = 0; i < enemies.size(); i++)
        delete enemies[i];
    delete[] line;
}

void GameState::endState()
{   
    ofstream fout;
    int rID = rand() % 1000;
    string batch= "data/" + to_string(rID) + "_user.txt";
 
    fout.open(batch);
    if (fout.is_open()) {
        fout << currentLevel << endl;
    }
    fout.close();
	cout << batch << endl;
}

void GameState::update()
{

    checkForPause();
    if (!this->pause) {
        this->checkForQuit();
        this->updateEnemies();
        people.update();
    }
    else {
        pauseMenu->update();
        if (pauseMenu->getPause()) {
            this->pause = false;
            pauseMenu->setPause(false);
        }
    }
    checkFromPause();

}

void GameState::render(sf::Event &ev, sf::RenderTarget* target)
{   
    if (!target)
        target = this->window;
    target->draw(background);
    if (!pause) {
        
        renderPlayer(ev);
    }
    renderEnemies();
    generateMap();

    if (this->pause) {
        //pause render
        pauseMenu->render(ev, this->window);
    }
}

void GameState::initPlayer()
{
    this->people = PEOPLE(400, 500, &this->textures["people"]);
}

void GameState::initEnemies() {}

void GameState::initTextures()
{
    sf::Texture tmp;

    tmp.loadFromFile("sprites/car.png");
    tmp.setSmooth(true);
    this->textures["car"] = tmp;

    tmp.loadFromFile("sprites/bird.png");
    tmp.setSmooth(true);
    this->textures["bird"] = tmp;

    tmp.loadFromFile("sprites/truck.png");
    tmp.setSmooth(true);
    this->textures["truck"] = tmp;

    tmp.loadFromFile("sprites/dino.png");
    tmp.setSmooth(true);
    this->textures["dino"] = tmp;

    tmp.loadFromFile("sprites/player3.png");
    tmp.setSmooth(true);
    this->textures["people"] = tmp;
}

void GameState::initBackground()
{
    this->background.setSize(sf::Vector2f((float)this->window->getSize().x, (float)this->window->getSize().y));
    if (!this->backgroundTexture.loadFromFile("images/bg1.png")) {
        throw "Texture load fail!! \n";
    }
    this->background.setTexture(&this->backgroundTexture);
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
            this->spawnEnemy();
            if (this->enemies[this->enemies.size() - 1]->Y() == this->enemies[this->enemies.size() - 2]->Y()) {
                this->enemies.pop_back();
            }
            enemySpawnTimer = 0.f;
        }
        else
            enemySpawnTimer += 1.f;
    }
    else {
        enemies.erase(enemies.begin());// 6 = max - 1
    }
    for (auto& e : this->enemies) 
        e->update();
}

void GameState::renderEnemies() {
    for (auto& e : this->enemies)
        e->Draw(this->window);
    for (auto& e : this->enemies) 
        e->Move((2.f + static_cast<float>(currentLevel - 1)), 0.f);
}


void GameState::renderPlayer(sf::Event &ev)
{
    this->people.Draw(this->window);
    this->people.KeyBoadMove_WithDt(46.f, ev);
}

void GameState::spawnEnemy() {
    unsigned tmp = static_cast<unsigned>(rand() % 4);
    switch (tmp)
    {
    case 0:
        this->enemy = new CTRUCK(&this->textures["truck"]);
        break;
    case 1:
        this->enemy = new CCAR(&this->textures["car"]);
        break;
    case 2:
        this->enemy = new CBIRD(&this->textures["bird"]);
        break;
    default:
        this->enemy = new CDINOSAUR(&this->textures["dino"]);
        break;
    }
    float tmpp = 130 + static_cast<float>((rand() % 4) * 92);//set location
    if (typeid(*this->enemy) == typeid(CTRUCK) || typeid(*this->enemy) == typeid(CBIRD))
        tmpp -= 20;
    this->enemy->setPosition(0.f, tmpp);
    
    this->enemies.push_back(enemy);
}

void GameState::generateMap()
{


    if (people.getY() <= 552.f) {//change from 100 to 552 because the sprite is something mysterious about the location
        if (currentLevel >= 3)
            setLevel(1);
        else {
            ++currentLevel;
            setLevel(currentLevel);
        }
        people.setPosition(400, 508);
        enemies.clear();
    }
}

void GameState::checkForPause()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        this->pause = true;
    }
}

void GameState::checkFromPause()
{
    if (this->pauseMenu->senderFromGame == 1) {
        setQuit(true);
    }
}

//MENU STATE

MenuState::MenuState(sf::RenderWindow* window, stack<State*>* states) :
    State(window, states)
{
    initFont();
    initButton();
    initBackground();
    ismoving = false;
}

void MenuState::initButton()
{
    currentButton = 0;

    this->rec[0].setSize(sf::Vector2f(200, 75));
    this->rec[1].setSize(sf::Vector2f(200, 75));
    this->rec[2].setSize(sf::Vector2f(200, 75));

    this->rec[0].setFillColor(sf::Color(255, 0, 0, 255));
    this->rec[1].setFillColor(sf::Color(0, 255, 0, 255));
    this->rec[2].setFillColor(sf::Color(0, 0, 255, 255));

    this->rec[0].setPosition(sf::Vector2f(300, 100));
    this->rec[1].setPosition(sf::Vector2f(300, 225));
    this->rec[2].setPosition(sf::Vector2f(300, 350));

    this->text[0].setString("NEW GAME");
    this->text[1].setString("LOAD GAME");
    this->text[2].setString("QUIT NOW");


    for (int i = 0; i < 3; i++) {
        text[i].setFillColor(sf::Color(255, 255, 255, 255));
        rec[i].setOutlineColor(sf::Color(255, 255, 255));
        text[i].setPosition(
            rec[i].getPosition().x + 40 - text[i].getLocalBounds().width / 2.f,
            rec[i].getPosition().y + 15 - text[i].getLocalBounds().height / 2.f
        );
        text[i].setCharacterSize(30);
        text[i].setFont(this->font);
        text[i].setStyle(sf::Text::Bold);
    }
}

void MenuState::initBackground() {
    this->background.setSize(sf::Vector2f((float)this->window->getSize().x, (float)this->window->getSize().y));
    if (!this->backgroundTexture.loadFromFile("images/bg1.png")) {
        throw "Texture load fail!! \n";
    }
    this->background.setTexture(&this->backgroundTexture);
}

MenuState::~MenuState()
{
    delete this->window;
}

void MenuState::endState()
{   
    cout << "End GameState" << endl;
}


void MenuState::nextButton(sf::Event ev)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        ismoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        ismoving = true;
    }

    if (ev.type == sf::Event::KeyReleased) {
        if (ev.key.code == sf::Keyboard::S && ismoving) {
            this->currentButton = (this->currentButton + 1) % 3;
            ismoving = false;
        }
        if (ev.key.code == sf::Keyboard::W && ismoving){
            this->currentButton = (this->currentButton + 2) % 3;
            ismoving = false;
        }
    }
}

void MenuState::highlight()
{
    for (int i = 0; i < 3; i++) 
        if (i != currentButton) 
            rec[i].setOutlineThickness(0);
        else 
            rec[i].setOutlineThickness(10);
}

void MenuState::initFont()
{
    if (!this->font.loadFromFile("font/Dosis-Light.ttf")) {
        throw("Font not found! \n");
    }
}

void MenuState::checkButton()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        if(currentButton == 0)
            this->states->push(new GameState(this->window, this->states));
        if (currentButton == 2)
            window->close();
    }
}

void MenuState::update()
{
    checkButton();
    highlight();
}

void MenuState::render(sf::Event &ev, sf::RenderTarget* target)
{
    nextButton(ev);
    if (!target)
        target = this->window;
    target->draw(background);
    for (int i = 0; i < 3; i++) {
        target->draw(rec[i]);
        target->draw(text[i]);
    }
}