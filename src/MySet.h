//
// Created by ikuzin on 15.02.2021.
//

#ifndef MYSET_H
#define MYSET_H

#include <string>
#include <iostream>
#include "iterator"

struct STR {
    STR(std::string &, STR *);

    std::string str;
    STR *next;
};


struct MYSET {
    std::string name;
    STR *head;
    STR *end;
public:
    bool operator==(MYSET const) const;

    explicit MYSET() {
        this->head = {};
        this->name = "";
    };

    explicit MYSET(std::string &name) : name(name) {
        head = nullptr;
        std::cout << "Пустое множество " << this->name << " создано\n";
    };

    [[nodiscard]] std::string getName() const { return this->name; }

    [[nodiscard]] STR *getHead() const { return this->head; }

    //---Методы---
    void add(std::string &);

    void del(const std::string &);

    bool in(const std::string &);

    void show();

    unsigned int card();
};

#endif
