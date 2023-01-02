#include "options.h"
#include <string>
#include <iostream>
#include <cstring>

// Name : Jamie Anzai
// ID : 5550091018

std::string usage(const char* y){
    std::string i = y;
    std::string x = "Usage: " + i + " [-h] [-v]\n";
    return x;
}
std::string help(const char* x){
    std::string y = usage(x);

    y += "to run the program interactively. To run using standard input:\necho 'equation' |./calc\nwhere 'equation' is a postfix notation equation, i.e. '2 2 +'\nor:\n ./calc < input_file.txt\nwhere 'input_file.txt' contains postfix notation equations, one per line\n\nOptions:\n\t-h Show this text\n\t-v Set a verbose output flag. Default = false.\n\nRunning with no input from standard in enters 'interactive mode'.\nEquations can be entered on per line.\nThe program runs until 'quit' is the first word on a line or EOF is reached.\n";
        return y;
}


option get_options(int x, char** y){
    option options;

    for(int i = 0; i < x; i++){
        if(strcmp(y[i] , "-h") == 0){
            std::cout << help(y[0]);
            exit(0);
        }
        if(strcmp(y[i] , "-v") == 0){
            options.verboseOutput = true;
        }
    }
    return options;
}


