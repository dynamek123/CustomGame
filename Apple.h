#pragma once
#ifndef APPLE_H
#define APPLE_H

#include "Sprite.h"

class Apple : public Sprite {
public:
   
    char getSymbol() const override;
    
};

#endif
