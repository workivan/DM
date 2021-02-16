//
// Created by ikuzin on 15.02.2021.
//

#include <iostream>
#include "Sets.h"
void SETS::printSets() const {
    if (this->list.empty()) {
        std::cout << "Список множеств пуст!!!\n";
        return;
    }
    for (const auto &it : this->list) {
        std::cout << "Название " << it.name << std::endl;
    }
}

void SETS::addSet(SET &set) {
    this->list.push_back(set);
}

void SETS::delSet(SET &set) {
    this->list.remove(set);
}
