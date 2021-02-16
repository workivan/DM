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
    bool input;
    std::string tmp;
    while (run) {
        std::cout << "Выбирайте, чем будем заниматься..:\n";
        std::cout << "1)Просмотреть список множеств\n";
        std::cout << "2)Добавить множество\n";
        std::cout << "3)Удалить множество\n";
        std::cout << "4)Использовать операции над множествами\n";
        std::cout << "5)Изменить множество\n";
        std::cout << "Любое число не принадлежащее R\\[1,2,3,4,5] - выход из пакета\n";
        std::string number;
        std::cin >> number;
        try {
            switch (atoi(number.c_str())) {
                case 1:
                    sets.printSets();
                case 2: {
                    while (input) {
                        input = true;
                        std::cout << "Дайте множеству имя..:";
                        std::cin >> tmp;
                        if (!std::all_of(tmp.begin(), tmp.end(), [](unsigned char c) { return std::isalpha(c); })) {
                            std::cout << "\nТОЛЬКО БУКВЫ..:";
                            continue;
                        }
                    }
                    SET set(tmp);
                    sets.addSet(set);
                    break;
                }
                case 3:
                    input = true;
                    while (input) {
                        std::cout << "Назовите имя удаляемого множества..:";
                        std::cin >> tmp;
                        if (std::all_of(tmp.begin(), tmp.end(), [](unsigned char c) { return std::isalpha(c); })) {
                            for (auto &it: sets.list) {
                                if (it.name == tmp) {
                                    sets.delSet(it);
                                }
                            }
                        }
                        std::cout << "\nНе нашли такого..Продолжим..?[y/n]\n..:";
                        std::cin >> tmp;
                        if (tmp[0] == 'y') {
                            std::cout << "Продолжаем поиски..:\n";
                            continue;
                        }
                        input = false;
                    }
                case 4:
                    menuMID();
                case 5: {
                    while (input) {
                        input = true;
                        std::cout << "Назовите имя множества..:";
                        std::cin >> tmp;
                        if (!std::all_of(tmp.begin(), tmp.end(), [](unsigned char c) { return std::isalpha(c); })) {
                            std::cout << "\nТОЛЬКО БУКВЫ..:";
                            continue;
                        }
                    }

                    break;
                }
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
