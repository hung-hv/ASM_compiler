#include <iostream>
#include "lexer.hpp"

int main() {
    lexer lex;
    int a= 10;
    char c = lex.NextChar();
    std::cout << lex.demo << std::endl;
    std::cout << a << std::endl;
    std::cout << c << std::endl;
    c = lex.NextChar();
    std::cout << c << std::endl;
    c = lex.NextChar();
    std::cout << c << std::endl;
    c = lex.NextChar();
    std::cout << c << std::endl;
    c = lex.NextChar();
    std::cout << c << std::endl;

    return 0;
}

// #include <iostream>

// int main() {
//     std::cout << "Hello, World!" << std::endl;
//     return 0;
// }