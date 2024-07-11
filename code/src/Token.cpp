#include "Token.hpp"

Token::Token() {
    
}

Token::Token (char* text, TokenType token_type) {
    Token_t token;
    
    this->textToken = text;
    this->kindToken = token_type;
}