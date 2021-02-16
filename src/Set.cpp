//
// Created by ikuzin on 15.02.2021.
//

#include "Set.h"

void SET::add(char *str) {
    if (this->head == nullptr) {
        this->head = new STR;
        this->head->str = str;
        this->head->next = nullptr;
    }
    STR *last = this->head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new STR;
    last->str = str;
}

void SET::del(const char *str) {
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

bool SET::in(char *str) {
    auto curr = this->head;
    while (curr != nullptr) {
        if (str == curr->str) return true;
        curr = curr->next;
    }
}

unsigned int SET::card() {
    unsigned int i = 0;
    auto curr = this->head;
    while (curr != nullptr) {
        i++;
        curr = curr->next;
    }
    return i;
}