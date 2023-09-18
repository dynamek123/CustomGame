#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include "Sprite.h"

class Monster : public Sprite {
public:
 
    char getSymbol() const override;
    int mXP = 0;
   
};

#endif
