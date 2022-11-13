#include "Game/Level1.h"
#include "Game/LevelTest.h"
#include <iostream>
#include "Game/Level2.h"

int main() {
    std::cout << "Введите уровень игры от 1 до 2" << "\n";
    char cur;
    std::cin >> cur;
    std::cin.ignore(1251, '\n');;
    while (cur < '1' || cur > '2') {
        std::cout << "Ошибка ввода, повторите ввод\n";
        std::cin >> cur;
        std::cin.ignore(1251, '\n');;
    }
    Level1 game1;
    Level2 game2;
    switch (cur) {
        case '1':
            game1.start();
            break;
        case '2':
            game2.start();
            break;
    }
    return 0;
}