#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "Engine.h"

class Keyboard : Engine{
public:
    void processInput();
private:
    Engine engine;
};


#endif // KEYBOARD_H