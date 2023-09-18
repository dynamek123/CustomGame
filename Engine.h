#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include "Sprite.h"
#include "Boss.h"
#include "Hero.h"
#include "Monster.h"
#include "Apple.h"

class Engine {
private:
 
    static const int MAX_LIVES = 10;
    static const int XP_GAIN = 1;

   
    Hero* hero;
    Boss* boss;
    std::vector<Monster*> monsters;
    int lives;
    bool gameWIN;
   
public:
    Engine();
    static const int BOARD_SIZE_Y = 20;
    static const int BOARD_SIZE_X = 20;
    Sprite* board[BOARD_SIZE_Y][BOARD_SIZE_X];
    void initializeGame();
    void placeSprite(Sprite* sprite, int x, int y);
    void moveHero(int dx, int dy);
    void gainXP(int amount);
    int getCurrentXP() const;
    int getLives() const;
    void findSprite(const Sprite* sprite, int& x, int& y) const;
    bool isValidPosition(int x, int y) const;
    bool isGameOver() const;
    
    bool hasWon() const;
};

#endif
