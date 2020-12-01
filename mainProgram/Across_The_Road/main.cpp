#include "includePath.h"

#include <iostream>

int main()
{   
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);
    
    OBJECT a = CBIRD(300.f, 300.f);/*Car(300.f, 300.f);*/
    

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
        
    }
}