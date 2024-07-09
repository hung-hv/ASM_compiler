#include <iostream>
#include "lexer.hpp"
#include "FileHandler.hpp"

int main() {
    char* filePath = "..//input//demo.txt";
    lexer lex;
    FileHandler FileHandler;
    std::string source_code = FileHandler.openFile(filePath);
    FileHandler.printFile();
    lex.getSrouce(source_code);
    lex.TestingLoop();

    return 0;
}

// #include <iostream>

// int main() {
//     std::cout << "Hello, World!" << std::endl;
//     return 0;
// }