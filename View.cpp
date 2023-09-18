#include "View.h"

View::View(Engine& e) : engine(e) {}

void View::displayGame() const {
    system("cls");
    for (int i = 0; i < Engine::BOARD_SIZE_X; ++i) {
        for (int j = 0; j < Engine::BOARD_SIZE_Y; ++j) {
            if (engine.board[i][j] != nullptr) {
                std::cout << engine.board[i][j]->getSymbol();
            }
            else if (i == Engine::BOARD_SIZE_X - 1 && (j == Engine::BOARD_SIZE_Y - 1 || j == 0)) {
                std::cout << '|';
            }
            else if (i == Engine::BOARD_SIZE_X - 1 || i == 0) {
                std::cout << '_';
            }
            else if (j == Engine::BOARD_SIZE_Y - 1 || j == 0) {
                std::cout << '|';
            }
            else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Aktualne zycia: " << engine.getLives() << std::endl;
    std::cout << "Aktualny poziom doswiadczenia (XP): " << engine.getCurrentXP() << std::endl;
    //std::cout << "Nacisnij klawisze W, A, S, D, aby poruszac bohaterem." << std::endl;

    if (engine.isGameOver()) {
        if (engine.hasWon()) {
            system("cls");
            std::cout << "Wygrales! Wszystkie potwory zostaly pokonane." << std::endl;
        }
        else {
            system("cls");
            std::cout << "Przegrales! Straciles wszystkie zycia." << std::endl;
        }
    }
    else {
        std::cout << "Nacisnij klawisze W, A, S, D, aby poruszac bohaterem." << std::endl;
    }
}

