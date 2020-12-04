#include "CGAME.h"

void CGAME::initWindow()
{
	settings.antialiasingLevel = 8;
	videoMode = sf::VideoMode(800, 600);
	window = new sf::RenderWindow(videoMode, "Across The Road", sf::Style::Default, settings);
}

void CGAME::initObject()
{
    this->people = PEOPLE(600, 300);
}

CGAME::CGAME()
{
	initWindow();
    initObject();
}

CGAME::~CGAME()
{
	delete this->window;
}

const bool CGAME::running() const
{
	return this->window->isOpen();
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
}

void CGAME::render()
{
    this->window->clear(/*sf::Color(255, 255, 255, 0)*/);
    //Draw game
    people.Draw(*this->window);

    this->window->display();
}
