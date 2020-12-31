#include "includePath.h"
#include "CGAME.h"
int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    //Init Game
    CGAME game;

    /*sf::Thread thread(&func);
    thread.launch();*/
    // run the program as long as the window is open

    /*sf::RenderWindow *window;
    sf::VideoMode videoMode = sf::VideoMode(800, 600);
    window = new sf::RenderWindow(videoMode, "Across The Road", sf::Style::Default);
    sf::Text text;
    sf::Font font;
    font.loadFromFile("font/Dosis-Light.ttf");
    text.setString("Alo");
    text.setFillColor(sf::Color(255, 255, 255));
    text.setCharacterSize(12);
    text.setFont(font);*/

    while (game.running())
    {
       //Update
       game.update();
       //Render
       game.render();
        //window->clear();
        //window->draw(text);
        //window->display();
    }
    return 0;
}