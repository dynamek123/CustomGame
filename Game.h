#pragma once
#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include "Keyboard.h"

class Game : Engine {
public:
    
    void start();
   void processInput();
 

private:
    Engine engine;
};

#endif
