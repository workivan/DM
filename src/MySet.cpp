//
// Created by ikuzin on 15.02.2021.
//

#include "MySet.h"
#include "string"

void MYSET::add(std::string &str) {
    if (this->head == nullptr) {
        this->head = new STR(str, nullptr);
        return;
    }
    STR *last = this->head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new STR(str, nullptr);
}

void MYSET::del(const std::string &str) {
    STR *prev, *curr = this->head;
    while (curr->str != str) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == this->head) {
        this->head = this->head->next;
    }
    prev->next = curr->next;
    delete curr;
}

bool MYSET::in(const std::string &str) {
    auto curr = this->head;
    while (curr != nullptr) {
        if (str == curr->str) return true;
        curr = curr->next;
    }
    return false;
}

unsigned int MYSET::card() {
    unsigned int i = 0;
    auto curr = this->head;
    while (curr != nullptr) {
        i++;
        curr = curr->next;
    }
    return i;
}

bool MYSET::operator==(MYSET const setb) const {
    if (this->head == setb.head && this->name == setb.name) return true;
    return false;
}

void MYSET::show() {
    auto curr = this->head;
    while (curr != nullptr) {
        std::cout << "эл = " << curr->str << std::endl;
        curr = curr->next;
    }
}

STR::STR(std::string &string, STR *str) {
    this->str = string;
    this->next = str;
}
