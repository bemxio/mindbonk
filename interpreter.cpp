#include "interpreter.h"
#include <iostream>
#include <vector>

void Interpreter::run(std::string &code) {
    int i = 0;
    std::vector<int> loops;
    
    while (i <= code.length() - 1) {
        switch (code[i]) {
            case '>':
                ++pointer;
                break;
            case '<':
                --pointer;
                break;
            case '+':
                ++*pointer;
                break;
            case '-':
                --*pointer;
                break;
            case '.':
                std::cout << char(*pointer);
                break;
            case ',':
                std::cin >> *pointer;
                break;
            case '[':
                if (*pointer == 0) {
                    i += code.substr(i).find("]");
                    continue;
                } else {
                    loops.push_back(i);
                };
                
                break;
            case ']':
                if (*pointer != 0) {
                    i = loops.back() + 1;
                    continue;
                } else {
                    loops.pop_back();
                };
                
                break;
        };
        
        i++;
    };
};