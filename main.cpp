#include "interpreter.h"
#include <algorithm>
#include <iostream>
#include <fstream>

int live() {
    Interpreter interpreter;
    std::string code;

    std::cout << "mindfuck: a brainfuck live interpreter" << std::endl;

    while (true) {
        std::cout << "=== ";
        std::cin >> code;

        interpreter.run(code);
        std::cout << std::endl;
    };
};

int main(int argc, char *argv[])
{   
    std::string argument;

    if (argc > 1) {
        argument = argv[1];
    } else {
        return live();
    };
    
    std::string code;

    if (argument == "-") {
        std::cin >> code;
    } else {
        std::ifstream file(argument);
        
        code = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
    }

    Interpreter interpreter;
    interpreter.run(code);

	return 0;
};