#include "tic_tac_toe.h"

int main(int argc, char** argv)
{
    bool ai_mode = false;

    if (argc == 2) {
        ai_mode = true;
    }

    tic_tac_toe *game = new tic_tac_toe(ai_mode);
    game->play();
    delete game;
}