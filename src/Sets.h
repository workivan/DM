//
// Created by ikuzin on 15.02.2021.
//


#include <list>
#include "Set.h"

struct SETS {
    std::list<SET> list;

    void printSets() const;
    void addSet( SET &set);
    void delSet( SET &set);
};

