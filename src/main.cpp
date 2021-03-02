#include <iostream>
#include <algorithm>
#include "MySets.h"
#include "MySet.h"

MYSETS *sets = new MYSETS;

void join(MYSET &a, MYSET &b) {
    std::string name = a.getName() + "or" + b.getName();
    MYSET *newSet;
    newSet = new MYSET(name);
    STR *head = a.head;
    while (head) {
        newSet->add(head->str);
        head = head->next;
    }
    head = b.getHead();
    while (head) {
        if (!newSet->in(head->str)) newSet->add(head->str);
        head = head->next;
    }
    sets->addSet(*newSet);
}

void cross(MYSET &a, MYSET &b) {
    std::string name = a.getName() + "and" + b.getName();
    MYSET *newSet;
    newSet = new MYSET(name);
    STR *headB, *headA = a.head;
    while (headA) {
        headB = b.head;
        while (headB) {
            if (headA->str == headB->str) {
                newSet->add(headA->str);
                break;
            }
            headB = headB->next;
        }
        headA = headA->next;
    }
    sets->addSet(*newSet);
}

void differ(MYSET &a, MYSET &b) {
    std::string name = a.getName() + "diff" + b.getName();
    MYSET *newSet;
    newSet = new MYSET(name);
    STR *headB, *headA = a.getHead();
    bool diff;
    while (headA) {
        diff = true;
        headB = b.head;
        while (headB) {
            if (headA->str == headB->str) {
                diff = false;
                break;
            }
            headB = headB->next;
        }
        if (diff) {
            newSet->add(headA->str);
        }
        headA = headA->next;
    }
    sets->addSet(*newSet);
}

void symDiffer(MYSET &a, MYSET &b) {
    cross(a, b);
    auto crossSet = sets->getLast();
    join(a, b);
    auto joinSet = sets->getLast();
    differ(*joinSet, *crossSet);
    sets->delSet(*crossSet);
    sets->delSet(*joinSet);
}

bool include(MYSET &a, MYSET &b) {
    bool include;
    if (a.card() > b.card()) {
        STR *headB, *headA = a.getHead();
        while (headA) {
            headB = b.getHead();
            while (headB) {
                include = false;
                if (headB->str == headA->str) {
                    include = true;
                }
                headB = headB->next;
            }
            if (!include) {
                return false;
            }
            headA = headA->next;
        }
        return true;
    } else {
        return false;
    }
}


void menuLOW(MYSET &set) {
    bool error, run = true;
    while (run) {
        std::cout << "Выбирайте, какую операцию применем..:\n";
        std::cout << "1)Добавить элемент\n";
        std::cout << "2)Удалить элемент\n";
        std::cout << "3)Содержит мно-во элемент ?\n";
        std::cout << "4)Вывести мощность\n";
        std::cout << "5)Вывести элементы\n";
        std::cout << "Любое число принадлежащее R\\[1,2,3,4,5] - выход из функции\n";
        std::string number, str;
        std::cin >> number;
        try {
            switch (std::stol(number)) {
                case 1:
                    std::cout << "Введите добавляемую строку..: ";
                    std::cin.ignore();
                    std::getline(std::cin, str);
                    std::cout << std::endl;
                    if (!set.in(str)) {
                        if (str.size() > 80) {
                            std::cout << "Слишком большая строка..\n";
                            error = true;
                        }
                        for (char n: str) {
                            if (n == '\"') {
                                std::cout << "Ковычка внутри..\n";
                                error = true;
                                break;
                            }
                        }
                        if (!error) {
                            set.add(str);
                            std::cout << "Добавили..: " << str << "\n";
                        }
                    } else {
                        std::cout << "Уже есть такой..\n";
                    }
                    error = false;
                    break;
                case 2:
                    std::cout << "Введите удаляемую строку..: ";
                    std::cin >> str;
                    std::cout << std::endl;
                    if (set.in(str)) {
                        set.del(str);
                        std::cout << "Удалили..: " << "\n";
                    } else {
                        std::cout << "Нет такого..: " << "\n";
                    }
                    break;
                case 3: {
                    std::cout << "Введите строку для поиска..: ";
                    std::cin >> str;
                    std::cout << std::endl;
                    auto response = set.in(str);
                    std::cout << " ->" << response << std::endl;
                    break;
                }
                case 4: {
                    auto response = set.card();
                    std::cout << " Мощность ->" << response << std::endl;
                    break;
                }
                case 5: {
                    set.show();
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

void menuMID() {
    MYSET a, b;
    bool go, input = true;
    std::string tmp, tmp1;
    while (input) {
        input = true;
        go = true;
        std::cout << "Назовите имя множества слева..:";
        std::cin >> tmp;
        if (!std::all_of(tmp.begin(), tmp.end(), [](unsigned char c) { return std::isalpha(c); })) {
            std::cout << "\nТОЛЬКО БУКВЫ..:";
            continue;
        }
        for (auto &i : sets->list) {
            if (i.name == tmp) {
                std::cout << "Нашли то, что нужно\n";
                a = i;
                go = false;
                break;
            }
        }
        if (go) {
            std::cout << "\nНе нашли такого..Продолжим..?[y/n]\n..:";
            std::cin >> tmp;
            if (tmp[0] == 'y') {
                std::cout << "Продолжаем поиски..:\n";
                continue;
            }
        }
        input = false;
    }
    input = true;
    while (input) {
        input = true;
        go = true;
        std::cout << "\nНазовите имя множества справа..:";
        std::cin >> tmp1;
        if (!std::all_of(tmp1.begin(), tmp1.end(), [](unsigned char c) { return std::isalpha(c); })) {
            std::cout << "\nТОЛЬКО АНГЛИЙСКИЕ БУКВЫ..:";
            continue;
        }
        for (auto &i : sets->list) {
            if (i.name == tmp1) {
                std::cout << "Нашли то, что нужно\n";
                b = i;
                go = false;
                break;
            }
        }
        if (go) {
            std::cout << "\nНе нашли такого..Продолжим..?[y/n]\n..:";
            std::cin >> tmp1;
            if (tmp[0] == 'y') {
                std::cout << "Продолжаем поиски..:\n";
                continue;
            }
        }
        input = false;
    }
    while (true) {
        std::cout << "Выбирайте, какую операцию применем..:\n";
        std::cout << "1)Обьединить мно-ва\n";
        std::cout << "2)Взять пересечение мно-в\n";
        std::cout << "3)Проверить на включение мно-ва справа в мно-во слева\n";
        std::cout << "4)Взять разность мно-в\n";
        std::cout << "5)Взять симметрическую разность мно-в\n";
        std::cout << "Любое число принадлежащее R\\[1,2,3,4,5] - выход из пакета\n";
        std::string number;
        std::cin >> number;
        try {
            switch (std::stol(number)) {
                case 1:
                    join(a, b);
                    std::cout << "Добавили его в список множеств\n";
                    break;
                case 2:
                    cross(a, b);
                    std::cout << "Добавили его в список множеств\n";
                    break;
                case 3:
                    go = include(a, b);
                    std::cout << "ответ = " << go << "\n";
                    break;
                case 4:
                    differ(a, b);
                    std::cout << "Добавили его в список множеств\n";
                    break;
                case 5:
                    symDiffer(a, b);
                    std::cout << "Добавили его в список множеств\n";
                    break;
                default:
                    return;
            }
        }
        catch (std::exception const &e) {
            std::cout << "Не корретный ввод...Давайте еще раз..:\n";
        }
    }
}


void menuUP() {
    bool run = true;
    bool input, go;
    std::string tmp;
    while (run) {
        input = true;
        go = true;
        std::cout << "Выбирайте, чем будем заниматься..:\n";
        std::cout << "1)Просмотреть список множеств\n";
        std::cout << "2)Добавить множество\n";
        std::cout << "3)Удалить множество\n";
        std::cout << "4)Использовать операции над множествами\n";
        std::cout << "5)Изменить множество\n";
        std::cout << "Любое число принадлежащее R\\[1,2,3,4,5] - выход из пакета\n";
        std::string number;
        std::cin >> number;
        try {
            switch (std::stol(number)) {
                case 1:
                    sets->printSets();
                    break;
                case 2: {
                    while (input) {
                        input = false;
                        std::cout << "Дайте множеству имя..:";
                        std::cin >> tmp;
                        if (!std::all_of(tmp.begin(), tmp.end(), [](unsigned char c) { return std::isalpha(c); })) {
                            std::cout << "\nТОЛЬКО АНГЛИСКИЕ БУКВЫ..:";
                            input = true;
                            continue;
                        }
                        for (const auto &name: sets->list) {
                            if (tmp == name.getName()) {
                                std::cout << "\nУже существует такое имя..:\n";
                                input = true;
                                break;
                            }
                        }
                        if (!input) {
                            MYSET *set;
                            set = new MYSET(tmp);
                            sets->addSet(*set);
                        }
                    }
                }
                    break;
                case 3:
                    while (input) {
                        std::cout << "Назовите имя удаляемого множества..:";
                        std::cin >> tmp;
                        if (!std::all_of(tmp.begin(), tmp.end(), [](unsigned char c) { return std::isalpha(c); })) {
                            std::cout << "\nТОЛЬКО АНГЛИСКИЕ БУКВЫ..:";
                            continue;
                        }
                        for (auto &it: sets->getList()) {
                            if (tmp == it.getName()) {
                                std::cout << "\nНашли то, что нужно и удалили\n";
                                sets->delSet(it);
                                go = false;
                                break;
                            }
                        }
                        if (go) {
                            std::cout << "\nНе нашли такого..Продолжим..?[y/n]\n..:";
                            std::cin >> tmp;
                            if (tmp[0] == 'y') {
                                std::cout << "Продолжаем поиски..:\n";
                                continue;
                            }
                        }
                        input = false;
                    }
                    break;
                case 4:
                    menuMID();
                    break;
                case 5:
                    while (input) {
                        input = false;
                        std::cout << "\nНазовите имя множества..:";
                        std::cin >> tmp;
                        if (!std::all_of(tmp.begin(), tmp.end(), [](unsigned char c) { return std::isalpha(c); })) {
                            std::cout << "\nТОЛЬКО АНГЛИСКИЕ БУКВЫ..:";
                            continue;
                        }
                        for (auto &it: sets->list) {
                            if (tmp == it.getName()) {
                                std::cout << "\nНашли то, что нужно";
                                menuLOW(it);
                                go = false;
                                break;
                            }
                        }
                        if (go) {
                            std::cout << "\nНе нашли такого..Продолжим..?[y/n]\n..:";
                            std::cin >> tmp;
                            if (tmp[0] == 'y') {
                                std::cout << "Продолжаем поиски..:\n";
                                continue;
                            }
                        }
                        input = false;
                    }
                    break;
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
    std::cout << "Приветствую Вас в теоретико-множественном пакете операций над множествами строк\n";
    menuUP();
    return 0;
}
