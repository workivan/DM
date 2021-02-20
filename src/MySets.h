//
// Created by ikuzin on 15.02.2021.
//

#ifndef MYSETS_H
#define MYSETS_H

#include <list>
#include "MySet.h"

struct MYSETS {
    std::list<MYSET> list;
public:
    std::list<MYSET> getList() { return this->list; };

    void printSets() const;

    void addSet(MYSET const &set);

    void delSet(MYSET const &set);

    MYSET *getLast();
};

#endif

