//
// Created by ikuzin on 15.02.2021.
//

#include "Set.h"

void SET::add(char* str) {
    if(this->head == nullptr){
        this->head = new STR;
        this->head->str = str;
        this->head->next = nullptr;
    }
    STR* last = this->head;
    while (last->next != nullptr){
        last = last->next;
    }
    last->next = new STR;
    last->str = str;
}

void SET::del(const char * str) {
    STR* prev, *curr = this->head;
    while (curr->str != str){
        prev = curr;
        curr = curr->next;
    }
    if(curr == this->head){
        this->head = this->head->next;
    }


}

bool SET::in(char* str) {
    return true;
}

int SET::card() {
    return 0;
}