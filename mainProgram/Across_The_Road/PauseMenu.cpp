#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow* window)
{
    this->senderFromGame = -1;
    this->window = window;
    initFont();
    initButton();
    initBackground();
    ismoving = false;
    unpause = false;
}

void PauseMenu::initButton()
{
    currentButton = 0;

    this->rec[0].setSize(sf::Vector2f(300, 75));
    this->rec[1].setSize(sf::Vector2f(300, 75));
    this->rec[2].setSize(sf::Vector2f(300, 75));

    this->rec[0].setFillColor(sf::Color(255, 0, 0, 255));
    this->rec[1].setFillColor(sf::Color(0, 255, 0, 255));
    this->rec[2].setFillColor(sf::Color(0, 0, 255, 255));

    this->rec[0].setPosition(sf::Vector2f(250, 100));
    this->rec[1].setPosition(sf::Vector2f(250, 225));
    this->rec[2].setPosition(sf::Vector2f(250, 350));

    this->text[0].setString("CONTINUE");
    this->text[1].setString("ENDGAME & REMOVE");
    this->text[2].setString("MAINMENU & SAVE");

    for (int i = 0; i < 3; i++) {
        text[i].setFillColor(sf::Color(255, 255, 255, 255));
        rec[i].setOutlineColor(sf::Color(255, 255, 255));
        text[i].setPosition(
            rec[i].getPosition().x + (rec[i].getSize().x / 2.f),
            rec[i].getPosition().y + (rec[i].getSize().y / 2.f)
        );
        text[i].setCharacterSize(30);
        text[i].setFont(this->font);
        text[i].setStyle(sf::Text::Bold);
    }
    
    this->text[0].setPosition(
        text[0].getPosition().x - 8*7.5f,
        text[0].getPosition().y - 20.f
    );
    this->text[1].setPosition(
        text[1].getPosition().x - 16 * 7.5f,
        text[1].getPosition().y - 20.f
    );
    this->text[2].setPosition(
        text[2].getPosition().x - 15 * 7.5f,
        text[2].getPosition().y - 20.f
    );
}

void PauseMenu::initBackground() {
    this->background.setSize(
        sf::Vector2f(
            (float)this->window->getSize().x,
            (float)this->window->getSize().y
        )
    );
    this->background.setFillColor(sf::Color(20, 20, 20, 100));

    this->container.setSize(
        sf::Vector2f(
            (float)this->window->getSize().x/2,
            (float)this->window->getSize().y
        )
    );
    this->container.setPosition(
        sf::Vector2f(
            (float)this->window->getSize().x / 4,
            0
        )
    );
    this->container.setFillColor(sf::Color(20, 20, 20, 200));
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::nextButton(sf::Event &ev)
{
    if (ev.key.code == sf::Keyboard::S) {
        this->currentButton = (this->currentButton + 1) % 3;
    }
    if (ev.key.code == sf::Keyboard::W) {
        this->currentButton = (this->currentButton + 2) % 3;
    }
    ev.key.code = sf::Keyboard::Unknown;
}

void PauseMenu::highlight()
{
    for (int i = 0; i < 3; i++)
        if (i != currentButton)
            rec[i].setOutlineThickness(0);
        else
            rec[i].setOutlineThickness(10);
}

bool PauseMenu::getPause() const
{
    return this->unpause;
}

void PauseMenu::setPause(bool up)
{
    this->unpause = up;
}

void PauseMenu::checkForUnpause()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->unpause = true;
        EndPause();
    }
}

void PauseMenu::checkButton(sf::Event& ev)
{
    if (ev.key.code == sf::Keyboard::Enter) {
        if (currentButton == 0)
            this->unpause = true;
        if (currentButton == 2) {
            this->unpause = true;
            this->senderFromGame = 1;
        }
    }
}

void PauseMenu::EndPause()
{
    cout << "End Pause menu \n";
        
}

void PauseMenu::initFont()
{
    if (!this->font.loadFromFile("font/Dosis-Light.ttf")) {
        throw("Font not found! \n");
    }
}

void PauseMenu::update()
{
    checkForUnpause();
    if (!this->unpause) {
        highlight();
    }
}

void PauseMenu::render(sf::Event &ev, sf::RenderTarget* target)
{
    checkButton(ev);
    nextButton(ev);
    if (!target)
        target = this->window;
    target->draw(background);
    for (int i = 0; i < 3; i++) {
        target->draw(rec[i]);
        target->draw(text[i]);
    }
}

MessageBox::MessageBox(sf::RenderWindow* window)
{
    this->window = window;
    initFont();
    initBackground();
    pause = false;
}

void MessageBox::initFont()
{
    if (!this->font.loadFromFile("font/Dosis-Light.ttf")) {
        throw("Font not found! \n");
    }
}

void MessageBox::initBackground()
{
    this->box.setSize(
        sf::Vector2f(
            (float)this->window->getSize().x,
            (float)this->window->getSize().y
        )
    );
    this->box.setFillColor(sf::Color(20, 20, 20, 100));
    this->text[0].setString("YOU LOSE");
    this->text[1].setString("Press Enter to continue !");

    text[0].setCharacterSize(30);
    text[0].setFont(this->font);
    text[0].setStyle(sf::Text::Bold);

    text[1].setCharacterSize(15);
    text[1].setFont(this->font);
    text[1].setStyle(sf::Text::Regular);

    text[0].setPosition(
        (float)this->window->getSize().x / 2 - 50.f,
        (float)this->window->getSize().y / 2 - 50.f
    );
    text[1].setPosition(
        (float)this->window->getSize().x / 2 - 60.f,
        (float)this->window->getSize().y / 2 - 0.f
    );
}

void MessageBox::draw(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;
    target->draw(box);
    target->draw(text[1]);
    target->draw(text[0]);
}

bool MessageBox::checkQuit(sf::Event& ev)
{
    if (ev.key.code == sf::Keyboard::Enter) {
        ev.key.code = sf::Keyboard::Unknown;
        return true;
    }
    return false;
}
