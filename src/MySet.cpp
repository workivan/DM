//
// Created by ikuzin on 15.02.2021.
//

#include "MySet.h"
#include "string"

void MYSET::add(std::string &str) {
    if (this->head == nullptr) {
        this->head = new STR(str, nullptr);
        this->end = this->head;
        return;
    }
    STR *last = this->end;
    last->next = new STR(str, nullptr);
    this->end = last->next;
}

void MYSET::del(const std::string &str) {
    STR *prev = NULL, *curr = this->head;
    while (curr->str != str) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == this->head) {
        this->head = this->head->next;
        return;
    }
    if (curr == this->end)
        this->end = prev;
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
