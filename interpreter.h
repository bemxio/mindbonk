#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

class Interpreter {
    public:
        char array[30000] = {0};
        char *pointer = array;
    
        void run(std::string &code);
};

#endif