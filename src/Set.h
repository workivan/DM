//
// Created by ikuzin on 15.02.2021.
//

#ifndef C_SET_H
#define C_SET_H
struct STR {
    char *str;
    STR *next;
};


struct SET {
    std::string name;
    STR *head;

    SET(std::string &name) : name(name) {
        head = nullptr;
        std::cout << "Пустое множество " << this->name << " создано\n";
    };

    ~SET() {
        delete head;
        std::cout << "Множество " << this->name << " удалено\n";
    };

    //---Методы---
    void add(char * str);

    void del(const char * str) ;

    bool in(char * str);

    unsigned int card();
};

//---Операции---
SET *join();

SET *differ();

SET *symDiffer();

SET *include();


#endif //C_SET_H
