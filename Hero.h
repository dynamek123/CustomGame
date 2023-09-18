#pragma once
#ifndef HERO_H
#define HERO_H

#include "Sprite.h"

class Hero : public Sprite {
public:
   
    int xp = 0;
    char getSymbol() const override;

};

#endif
