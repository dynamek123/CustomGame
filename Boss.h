#pragma once
#ifndef BOSS_H
#define BOSS_H

#include "Sprite.h"

class Boss : public Sprite {
public:
   
    char getSymbol() const override;
    int bXP = 30;
  
};

#endif
