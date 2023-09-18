#include "Engine.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Engine::Engine() : hero(nullptr), lives(MAX_LIVES) {
    for (int i = 0; i < BOARD_SIZE_X; ++i) {
        for (int j = 0; j < BOARD_SIZE_Y; ++j) {
            board[i][j] = nullptr;
        }
    }
}

void Engine::initializeGame() {
    hero = new Hero();
    placeSprite(hero, 1, 1);
    srand(static_cast<unsigned>(time(NULL)));

    int monsters_n = (rand() % 30) + 3;
    int apple_n = (rand() % 20) + 10;
    for (int i = 0; i < monsters_n; i++) {
        monsters.push_back(new Monster());
        monsters[i]->mXP = (rand() % 15) + 1;
        placeSprite(monsters[i], (rand() % 15) + 2, monsters[i]->mXP);
    }

    placeSprite(new Boss(), 18, 18);

    for (int i = 0; i < apple_n; i++) {
        placeSprite(new Apple(), (rand() % 10) + 2, (rand() % 10) + 2);
    }
}

void Engine::placeSprite(Sprite* sprite, int x, int y) {
    if (x >= 0 && x < BOARD_SIZE_X && y >= 0 && y < BOARD_SIZE_Y) {
        board[x][y] = sprite;
    }
}



void Engine::moveHero(int dx, int dy) {
    int heroX, heroY;
    findSprite(hero, heroX, heroY);

    int newHeroX = heroX + dx;
    int newHeroY = heroY + dy;

    if (isValidPosition(newHeroX, newHeroY)) {
        Sprite* destination = board[newHeroX][newHeroY];
        if (destination == nullptr) {
            board[heroX][heroY] = nullptr;
            placeSprite(hero, newHeroX, newHeroY);
        }
        else if (dynamic_cast<Apple*>(destination) != nullptr) {
            board[heroX][heroY] = nullptr;
            placeSprite(hero, newHeroX, newHeroY);
            delete destination;
            gainXP(XP_GAIN);
        }
        else if (dynamic_cast<Monster*>(destination) != nullptr) {
            if (getCurrentXP() > newHeroX) {
                board[heroX][heroY] = nullptr;
                placeSprite(hero, newHeroX, newHeroY);
                delete destination;
                gainXP(XP_GAIN);
            }
            else {
                lives--;
            }
        }
        else if (dynamic_cast<Boss*>(destination) != nullptr) {
            if (getCurrentXP() > 30) {
                gameWIN = true;
            }
            else {
                lives--;
            }
        }
    }
}

void Engine::gainXP(int amount) {
    hero->xp = hero->xp + amount;
    
}

int Engine::getCurrentXP() const {
    return hero->xp;
}

void Engine::findSprite(const Sprite* sprite, int& x, int& y) const {
    for (int i = 0; i < BOARD_SIZE_X; ++i) {
        for (int j = 0; j < BOARD_SIZE_Y; ++j) {
            if (board[i][j] == sprite) {
                x = i;
                y = j;
                return;
            }
        }
    }
}

bool Engine::isValidPosition(int x, int y) const {
    return (x >= 1 && x < BOARD_SIZE_X - 1 && y >= 1 && y < BOARD_SIZE_Y - 1);
}

bool Engine::isGameOver() const {
    return gameWIN || lives <= 0;
}

bool Engine::hasWon() const {
    return gameWIN;
}

int Engine::getLives() const {
    return lives;
}

