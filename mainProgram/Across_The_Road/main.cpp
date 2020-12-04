#include "includePath.h"
#include "CGAME.h"
int main()
{   
    //Init Game
    CGAME game;

    //sf::Thread thread(&func);
    //thread.launch();

    // run the program as long as the window is open
    while (game.running())
    {

        //Update
        game.update();
        //Render
        game.render();
    }
    return 0;
}