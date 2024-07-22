#include "Token.hpp"
#include <cstdlib> // Include the necessary header file
#include <stdio.h>
#include <string.h>


Token::Token() {
    // this->Token.textToken = "";
    // this->Token.kindToken = "";
}


Token::Token_t Token::CreateToken(char c_char, TokenType token_type) {
    Token_t token;
    *(token.textToken) = c_char;
    token.kindToken = token_type;
    return token;
}

Token::Token_t Token::CreateToken(char* c_text, int c_size, TokenType token_type) {
    Token_t token;
    token.textToken = static_cast<char*>(std::malloc(c_size * sizeof(char))); // Use std::malloc instead of malloc
    strcpy(token.textToken, c_text);
    // token.textToken = c_text;
    token.kindToken = token_type;
    return token;
}



