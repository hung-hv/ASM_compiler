#include <iostream>
#include "lexer.hpp"
#include "FileHandler.hpp"
#include "Token.hpp"

int main() {
    char* filePath = "..//input//demo.txt";
    lexer lex;
    Token token;
    FileHandler FileHandler;
    std::string source_code = FileHandler.openFile(filePath);
    FileHandler.printFile();
    lex.getSrouce(source_code);
    // lex.TestingLoop();
    token.TokenObj = lex.GetToken();
    std::cout << "Token: " << token.TokenObj.kindToken << std::endl;
    while (token.TokenObj.kindToken != Token::TokenType::EOFILE) {
        // std::cout << "Token: " << token.TokenObj.kindToken << std::endl;
        token.TokenObj = lex.GetToken();
    
    }

    return 0;
}

// #include <iostream>

// int main() {
//     std::cout << "Hello, World!" << std::endl;
//     return 0;
// }