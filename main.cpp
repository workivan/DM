#include <iostream>
#include <algorithm>
#include "src/Sets.h"

SETS sets;

void menuMID() {
    std::cout << "Выбирайте, какую операцию применем..:\n";
    std::cout << "1)Обьединить мно-ва\n";
    std::cout << "2)Взять пересечение мно-в\n";
    std::cout << "3)Взять разность мно-в\n";
    std::cout << "4)Взять симметрическую разность мно-в\n";
    std::cout << "5)Проверить на включение мно-ва в другое\n";
    std::string number;
    std::cin >> number;
    try {
        switch (atoi(number.c_str())) {
            case 1:
                printSets();
            case 2:
                addSet();
            case 3:
                delSet();
            case 4:
                bool runMID = true;
                while (runMID) {
                    menuMID();
                    runMID = false;
                }
            default:
                return;
        }
    }
    catch (std::exception const &e) {
        std::cout << "Не корретный ввод...Давайте еще раз..:\n";
    }
}


void menuUP() {
    bool run = true;
    while (run) {
        std::cout << "Выбирайте, чем будем заниматься..:\n";
        std::cout << "1)Просмотреть список множеств\n";
        std::cout << "2)Добавить множество\n";
        std::cout << "3)Удалить множество\n";
        std::cout << "4)Использовать операции над множествами\n";
        std::cout << "Любое число не принадлежащее R\\[1,2,3,4] - выход из пакета\n";
        std::string number;
        std::cin >> number;
        try {
            switch (atoi(number.c_str())) {
                case 1:
                    sets.printSets();
                case 2:

                    sets.addSet();
                case 3:
                    sets.delSet();
                case 4:
                    menuMID();
                default:
                    return;
            }
        }
        catch (std::exception const &e) {
            std::cout << "Не корретный ввод...Давайте еще раз..:\n";
        }
    }
}

int main() {
    auto sets = new SETS;
    std::cout << "Приветствую Вас в теоретико-множественном пакете пераций над множествами строк\n";
    menuUP();
    return 0;
}
