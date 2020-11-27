#include "includePath.h"
#include <SFML/Graphics.hpp>
#include <limits>

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 500), "SFML-Tutorial", sf::Style::Close);
    window.setFramerateLimit(60);

    sf::RectangleShape rectang(sf::Vector2f(400, 220));

    rectang.setPosition(250, 140);
    rectang.setFillColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
            {
                window.close();
            }
        }

        window.clear();

        window.draw(rectang);

        window.display();
    }

    return 0;
}