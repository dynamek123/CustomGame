#include "Keyboard.h"
#include <iostream>
#include <vector>
#include <conio.h> 
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include "View.h"
#include "Engine.h"

void Keyboard::processInput() {
    View view(engine);
    if (_kbhit()) {
        char input = _getch();
        switch (input) {
        case 'w':
        case 'W':
            engine.moveHero(-1, 0);
            view.displayGame();
            break;
        case 'a':
        case 'A':
            engine.moveHero(0, -1);
            view.displayGame();
            break;
        case 's':
        case 'S':
            engine.moveHero(1, 0);
            view.displayGame();
            break;
        case 'd':
        case 'D':
            engine.moveHero(0, 1);
            view.displayGame();
            break;
        }
    }
}