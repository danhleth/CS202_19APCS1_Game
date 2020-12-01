#include "includePath.h"

#include <iostream>

int main()
{   
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);
    

    COBJECT a = PEOPLE(0.f, 100.f);
    COBJECT b = CDINOSAUR(0.f, 200.f);
    COBJECT e = CBIRD(0.f, 500.f);
    COBJECT c = CCAR(0.f, 300.f);
    COBJECT d = CTRUCK(0.f, 400.f);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color

        // draw everything here...
        // window.draw(...);
        a.Draw(window);
        a.KeyBoardMove(0.3f ,0.3f);
        window.clear();
        a.Draw(window);
        window.display();
        // end the current frame
        b.Draw(window);
        b.KeyBoardMove(0.3f, 0.3f);
        window.clear();
        b.Draw(window);
        window.display();
        c.Draw(window);
        c.KeyBoardMove(0.3f, 0.3f);
        window.clear();
        c.Draw(window);
        window.display(); 
        d.Draw(window);
        d.KeyBoardMove(0.3f, 0.3f);
        window.clear();
        d.Draw(window);
        window.display();
        e.Draw(window);
        e.KeyBoardMove(0.3f, 0.3f);
        window.clear();
        e.Draw(window);
        window.display();
    }
}