#include <iostream>
#include <fstream>

#include <algorithm>
#include <vector>

class Interpreter {
    public:
        char array[30000] = {0};
        char *pointer = array;
    
        void run(std::string &code);
};

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

int main(int argc, char *argv[])
{
    std::string argument = argv[1];
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