#include "includePath.h"

#include <iostream>

int main()
{   
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);
    

    COBJECT a = PEOPLE(50.f, 100.f);
    COBJECT b = CDINOSAUR(100.f, 100.f);
    COBJECT e = CBIRD(200.f, 100.f);
    COBJECT d = CCAR(250.f, 100.f);
    COBJECT c = CTRUCK(350, 100.f);
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
        b.Draw(window);
        c.Draw(window);
        d.Draw(window);
        e.Draw(window);
        //a.KeyBoardMove(0.3f ,0.3f);
        /*window.clear();*/
        a.Draw(window);
        window.display();
        // end the current frame
        /*b.Draw(window);
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
        window.display();*/
    }
    return 0;
}