//
// Created by ikuzin on 15.02.2021.
//

#ifndef C_SET_H
#define C_SET_H
#define MAX_SET_STR 80
struct STR {
    char *str;
    STR *next;
};


struct SET {
    std::string name;
    STR *head;

    SET(std::string &name) : name(name) {
        head = nullptr;
        std::cout << "Множество " << this->name << " создано\n";
    };
    SET(std::string &name, char* str) : name(name) {
        head = new STR;
        head->str = str;
        head->next = nullptr;
        std::cout << "Множество " << this->name << " создано\n";
    };

    ~SET() {
        delete head;
        std::cout << "Множество " << this->name << " удалено\n";
    };

    //---Методы---
    char *add(char * str);

    char *del(char * str);

    bool in(char * str);

    int card();
};

//---Операции---
SET *join();

SET *differ();

SET *symDiffer();

SET *include();


#endif //C_SET_H
