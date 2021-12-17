#include <iostream>
#include <cmath>

std::string codeify(std::string &text) {
    std::string code;
    char n = 0;

    int tens; int rest;
    std::string operation = "+";

    for (int i = 0; i < text.length(); i++) {
        n = int(text[i]);

        tens = round(n / 10);
        rest = n % 10;

        for (int j = 0; j < tens; j++) {
            code += "+";
        }

        code += "[>++++++++++<-]";
        
        /*
        if (rest > 5) {
            rest = 10 - rest;
            operation = "-";
        } else {
            operation = "+";
        }
        */
       
        code += ">";

        for (int j = 0; j < rest; j++) {
            code += operation;
        }

        code += ".[-]<";
    };

    return code;
};

int main(int argc, char *argv[]) {
    std::string text = argv[1];

    std::cout << codeify(text) << std::endl;
    return 0;
}