#include "CGAME.h"

CGAME::CGAME()
{
    initWindow();
    initStates();
   // initBackground();
}

CGAME::~CGAME()
{
    while (this->states.empty()) {
        delete states.top();
        states.pop();
    }
}

void CGAME::initWindow()
{
    settings.antialiasingLevel = 8;
    videoMode = sf::VideoMode(800, 600);
    window = new sf::RenderWindow(videoMode, "Across The Road", sf::Style::Default, settings);
    this->window->setKeyRepeatEnabled(false);
    this->window->setFramerateLimit(60);//not understand
}

const bool CGAME::running() const
{
    return this->window->isOpen();
}

void CGAME::initStates()
{
    states.push(new MenuState(this->window, &this->states));
    //states.push(new GameState(this->window));
}

/*void CGAME::initBackground() {
    this->background.setSize(sf::Vector2f((float)this->window->getSize().x, (float)this->window->getSize().y));
    if (!this->backgroundTexture.loadFromFile("images/bg1.png")) {
        throw "Texture load fail!! \n";
    }
    this->background.setTexture(&this->backgroundTexture);
}*/

void CGAME::pollEvent()
{
    while (this->window->pollEvent(this->event)) {
        switch (event.type)
        {
        case sf::Event::Closed:
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
    if (!this->states.empty()) {
        this->states.top()->update();
        if (this->states.top()->getQuit()) {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else {
        this->window->close();
    }
}

void CGAME::render()
{
    this->window->clear(/*sf::Color(255, 255, 255, 0)*/);

    if (!this->states.empty()) {
        this->states.top()->render(this->event);
    }
    this->window->display();
}

