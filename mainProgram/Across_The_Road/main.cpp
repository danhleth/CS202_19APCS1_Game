#include "includePath.h"
#include "CGAME.h"
int main()
{
        srand(static_cast<unsigned>(time(NULL)));
        //Init Game
        CGAME game;

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