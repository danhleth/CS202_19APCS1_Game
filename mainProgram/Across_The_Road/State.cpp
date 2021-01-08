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
    initTrafficLights();
    initSound();
    this->pauseMenu = new PauseMenu(this->window);
    this->messageBox = new MessageBox(this->window);
    this->points = 0;
    this->enemySpawnTimerMax = 120.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 7;
    //this->backgroundSound.play();
}

GameState::~GameState()
{
    int n = enemies.size();
    for (int i = 0; i < n; i++)
        delete enemies[i];
    n = trafficLights.size();
    for (int i = 0; i < n; i++)
        delete trafficLights[i];
    delete[] line;
}

void GameState::endState()
{
	cout << "End GameState" << endl;
}

void GameState::update()
{

    checkForPause();
    checkImpact();
    if (!this->pause) {
        this->checkForQuit();
        this->updateEnemies();
        this->updateTrafficLights();
        people.update();
    }
    else {
        if (!this->messageBox->pause) {
            pauseMenu->update();
            if (pauseMenu->getPause()) {
                this->pause = false;
                pauseMenu->setPause(false);
            }
        }
    }
    checkFromPause();

}

void GameState::render(sf::Event &ev, sf::RenderTarget* target)
{   
    if (!target)
        target = this->window;
    target->draw(background);
    renderPlayer(ev);
    renderEnemies();
    renderTrafficLights();
    generateMap();

    if (this->pause) {
        //pause render
        if (this->messageBox->pause) {
            messageBox->draw(this->window);
            if (messageBox->checkQuit(ev)) {
                setQuit(true);
            }
        }
        else
            pauseMenu->render(ev, this->window);
    }
}

void GameState::initPlayer()
{
    this->people = PEOPLE(400, 500, &this->textures["people"], &this->soundBuffers["people"]);
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

    tmp.loadFromFile("trafficLights/red.jfif");
    tmp.setSmooth(true);
    this->textures["red"] = tmp;

    tmp.loadFromFile("trafficLights/yellow.jpg");
    tmp.setSmooth(true);
    this->textures["yellow"] = tmp;

    tmp.loadFromFile("trafficLights/blue.jpg");
    tmp.setSmooth(true);
    this->textures["blue"] = tmp;

    tmp.loadFromFile("sprites/death.png");
    tmp.setSmooth(true);
    this->textures["people_dead"] = tmp;
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

void GameState::initTrafficLights() {
    currentTrafficLights = 3;
    this->trafficLightsSpawnTimer = 120.f;
    this->trafficLightsSpawnTimerMax = this->trafficLightsSpawnTimer;
    COBJECT* tmp = new CTRUCK(&this->textures["red"], &this->soundBuffers["car"]);
    tmp->setPosition(550.f, 40.f);
    tmp->setScale(0.21f, 0.21f);
    tmp->setColor(0.f, 0.f, 0.f);
    trafficLights.push_back(tmp);
    tmp = new CTRUCK(&this->textures["yellow"], &this->soundBuffers["car"]);
    tmp->setPosition(602.5f, 40.f);
    tmp->setScale(0.07f, 0.07f);
    tmp->setColor(0.f, 0.f, 0.f);
    trafficLights.push_back(tmp);
    tmp = new CTRUCK(&this->textures["blue"], &this->soundBuffers["car"]);
    tmp->setPosition(650.f, 40.f);
    tmp->setScale(0.11f, 0.125f);
    tmp->setColor(0.f, 0.f, 0.f);
    trafficLights.push_back(tmp);
}

void GameState::initSound()
{
    sf::SoundBuffer soundTmp;
    soundTmp.loadFromFile("sound/bird.wav");
    soundBuffers["bird"] = soundTmp;
    soundTmp.loadFromFile("sound/car_sound.wav");
    soundBuffers["car"] = soundTmp;
    soundTmp.loadFromFile("sound/dino.wav");
    soundBuffers["dino"] = soundTmp;
    soundTmp.loadFromFile("sound/people_footstep.wav");
    soundBuffers["people"] = soundTmp;

    sf::Sound sound;
    sound.setBuffer(soundBuffers["birds"]);
    sounds["birds"] = sound;
    sound.setBuffer(soundBuffers["car"]);
    sounds["car"] = sound;
    sound.setBuffer(soundBuffers["dino"]);
    sounds["dino"] = sound;
    sound.setBuffer(soundBuffers["people"]);
    sounds["people"] = sound;

    /*if (!this->backgroundSound.openFromFile("sound/BackGround.wav")) {
        cout << "Can not open music file" << endl;
    }*/
}

void GameState::setLevel(unsigned level) {
    /*if (level > MAX_LEVEL)
        return;*/
    currentLevel = level;

    //this->points = 0;
    this->enemySpawnTimerMax = (140.f - static_cast<float>((level - 1) * 40));
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 15;// loop some   times
}

void GameState::updateEnemies() {
    if (this->enemies.size() < this->maxEnemies) {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            //spaw the enemy and reset the timer
            this->spawnEnemy();
            int keepSize = this->enemies.size();
            for (int i = 0; i < this->currentLevel; i++) {
                this->spawnEnemy();
                int keepCurrentSize = this->enemies.size();
                float checkSameLine = this->enemies[static_cast<int>(keepCurrentSize - 1)]->Y();
                for (unsigned j = keepSize; j < keepCurrentSize; j++) {
                    float checkSameLine1 = this->enemies[j - 1]->Y();
                    if (checkSameLine == checkSameLine1 || (checkSameLine == checkSameLine1 - 20) ||
                        checkSameLine == checkSameLine1 + 20) {
                        this->enemies.pop_back();
                        break;
                    }
                }
                if (this->enemies.size() == keepCurrentSize) {
                    this->enemies[this->enemies.size() - 1]->
                        setPosition(-100.f, this->enemies[this->enemies.size()-1]->Y());
                }
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

    for (auto& e : this->enemies) {
        e->Draw(this->window);
        /*if (typeid(*e) == typeid(CTRUCK) || typeid(*e) == typeid(CCAR)) {
            sounds["car"].play();
        }
        if (typeid(*e) == typeid(CBIRD)) {
            sounds["bird"].play();
        }
        if (typeid(*e) == typeid(CDINOSAUR)) {
            sounds["dino"].play();
        }*/
    }
    if (!this->pause) {
        for (auto& e : this->enemies) {//red, yellow, green
            if (typeid(*e) == typeid(CTRUCK) || typeid(*e) == typeid(CCAR)) {
                if (currentTrafficLights == 2)
                    e->Move(((3.f + (static_cast<float>(currentLevel - 1))) / 2) / 2, 0.f);
                else if (currentTrafficLights == 1)
                    e->Move(0.f, 0.f);
                else
                    e->Move((3.f + (static_cast<float>(currentLevel - 1))) / 2, 0.f);
            }
            else 
              e->Move((3.f + (static_cast<float>(currentLevel - 1))) / 2, 0.f);
        }
    }
}


void GameState::renderPlayer(sf::Event &ev)
 {
    this->people.Draw(this->window);
    if (!this->pause) {
        this->people.KeyBoadMove_WithDt(46.f, ev);
    }
}

void GameState::updateTrafficLights() {
    if (this->trafficLightsSpawnTimer < this->trafficLightsSpawnTimerMax)
        this->trafficLightsSpawnTimer++;
    else {
        if (currentTrafficLights <= 1)
            currentTrafficLights = 3;
        else
            currentTrafficLights--;
        if (currentTrafficLights == 1) {
            this->trafficLights[1]->setColor(0.f, 0.f, 0.f);
            this->trafficLights[0]->setColor(255.f, 255.f, 255.f);//red
        }
        else if (currentTrafficLights == 2) {
            this->trafficLights[2]->setColor(0.f, 0.f, 0.f);
            this->trafficLights[1]->setColor(255.f, 255.f, 0.f);//yellow
        }
        else {
            this->trafficLights[0]->setColor(0.f, 0.f, 0.f);
            this->trafficLights[2]->setColor(0.f, 255.f, 0.f);
        }
        this->trafficLightsSpawnTimer = 0.f;
    }
}

void GameState::renderTrafficLights(){
    for (auto& e : this->trafficLights)
        e->Draw(this->window);
}


void GameState::spawnEnemy() {
    COBJECT* enemyTmp = nullptr;
    unsigned tmp = static_cast<unsigned>(rand() % 4);
    switch (tmp)
    {
    case 0:
        enemyTmp = new CTRUCK(&this->textures["truck"], &this->soundBuffers["car"]);
        break;
    case 1:
        enemyTmp = new CCAR(&this->textures["car"], &this->soundBuffers["car"]);
        break;
    case 2:
        enemyTmp = new CBIRD(&this->textures["bird"], &this->soundBuffers["bird"]);
        break;
    default:
        enemyTmp = new CDINOSAUR(&this->textures["dino"], &this->soundBuffers["dino"]);
        break;
    }
    float tmpp = 130 + static_cast<float>((rand() % 4) * 92);//set location
    if (typeid(*enemyTmp) == typeid(CTRUCK) || typeid(*enemyTmp) == typeid(CBIRD))
        tmpp -= 20;
    enemyTmp->setPosition(0.f, tmpp);
    this->enemies.push_back(enemyTmp);
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

void GameState::checkImpact()
{
    if (this->people.isImpact(this->enemies)) {
        int x = people.position().x, y = people.position().y;
        people = PEOPLE(x, y, &this->textures["people_dead"], &this->soundBuffers["people"]);
        this->pause = true;
        this->messageBox->pause = true;
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