//
// Created by ikuzin on 15.02.2021.
//


#include "MySets.h"
#include "algorithm"

void MYSETS::printSets() const {
    if (this->list.empty()) {
        std::cout << "Список множеств пуст!!!\n";
        return;
    }
    for (auto &it : this->list) {
        std::cout << "Название - " << it.getName() << std::endl;
    }
}

void MYSETS::addSet(MYSET const &set) {
    this->list.push_back(set);
}

void MYSETS::delSet(MYSET const &set) {
    this->list.remove(set);
}

MYSET *MYSETS::getLast() {
    return &this->list.back();
}
