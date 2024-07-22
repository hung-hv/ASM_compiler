#include "lexer.hpp"

#include <string.h>

lexer::lexer(/* args */)
{
    // char* demo = NULL;
    // demo = (char*)malloc(sizeof(char) * strlen(this->demo));
    // demo = "this is a test";
    // this->curChar = (char*)this->demo;
    this->curChar = " ";
    this->curPos = -1;
    this->sourceSize = 0;
}

lexer::~lexer()
{
    
    // free(this->demo);
    free(this->curChar);
}

char lexer::NextChar()
{
    this->curPos++;
    this->curChar = this->c_source + this->curPos;
    char c = *(this->curChar);
    if (messageActivate != 0) {
        std::cout << "  NextChar: " << c << std::endl;
    }
    
    return c;
}

char lexer::PeekChar() {
    char c = ' ';
    if ( (this->curPos + 1) >= this->sourceSize ) {
        c = '\0';
    } else {
        c = this->c_source[this->curPos + 1];
    }
    if (messageActivate != 0) {
        std::cout << "  PeekChar: " << c << std::endl;
    }
    return c;
}

int lexer::getSrouce(std::string source) {
    if (source.empty()) {
        std::cout << "<!> source is empty" << std::endl;
        return 0; //error
    } else {
        this->s_source = source;
        this->sourceSize = source.length();
        this->c_source = (char*)malloc(sizeof(char) * this->sourceSize);
        strcpy(this->c_source, source.c_str());
        if (messageActivate != 0) {
            std::cout << "-> source added" << std::endl;
            std::cout << "  -> size = " << this->sourceSize << std::endl;
        }
        return 1; //success
    }
}

void lexer::TestingLoop() {
    char curChar = ' ';
    char peekChar = ' ';
    while (curChar != '\0') {
        curChar = this->NextChar();
        peekChar = this->PeekChar();
        if (messageActivate != 0) {
            std::cout << "  curChar: " << curChar << std::endl;
            std::cout << "  peekChar: " << peekChar << std::endl;
        }
    }
}

Token::Token_t lexer::GetToken() {
    // std::cout << "<!> Token" << std::endl;
    // Token::Token_t token;
    Token eToken; //instance of Token
    eToken.TokenObj.textToken = NULL;
    eToken.TokenObj.kindToken = Token::UNKNOW;
    // std::cout << "<!> create instance of Token" << std::endl;
    // Token eToken; //instance of token
    // eToken.Token
    char c = *(this->curChar);
    // std::cout << c << std::endl;
    if (c == '+') {
        eToken.TokenObj = eToken.CreateToken(c, Token::PLUS);
    } else if (c == '-') {
        eToken.TokenObj = eToken.CreateToken(c, Token::MINUS);
    } else if (c == '*') {
        eToken.TokenObj = eToken.CreateToken(c, Token::ASTERISK);
    } else if (c == '/') {
        eToken.TokenObj = eToken.CreateToken(c, Token::SLASH);
    } else if (c == '\n') { //new line
        eToken.TokenObj = eToken.CreateToken(c, Token::NEWLINE);
    } else if (c == '\0') { //EOF
        eToken.TokenObj = eToken.CreateToken(c, Token::EOFILE);
    } else { // Unknow token
        if (messageActivate != 0) {
            std::cout << "<!> Unknow Token" << std::endl;
        }
    }
    if (eToken.TokenObj.kindToken != Token::UNKNOW) {
        if (messageActivate != 0) {
            std::cout << eToken.TokenObj.textToken << std::endl;
            std::cout << eToken.TokenObj.kindToken << std::endl;
        }
    }
        
    // lex to next char
    this->NextChar();
    return eToken.TokenObj;
}

void lexer::SkipWhiteSpace() {
    char c = *(this->curChar);
    while ( (c == ' ') || (c == '\t') || (c == '\r')) {
        if (messageActivate != 0) {
            std::cout << "<!> WhiteSpace" << std::endl;
        }
        this->NextChar();
    }
}

// void lexer::PushMessage (std::string message) {
//     if (messageActivate != 0) { //push message to serial window
//         std::cout << "TestingLoop: " << c << std::endl;
//     }
// }