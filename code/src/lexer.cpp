#include "lexer.hpp"
#include "Token.hpp"
#include <string.h>

lexer::lexer(/* args */)
{
    // char* demo = NULL;
    // demo = (char*)malloc(sizeof(char) * strlen(this->demo));
    // demo = "this is a test";
    // this->curChar = (char*)this->demo;
    this->curChar = NULL;
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

int lexer::isToken() {
    char c = *(this->curChar);
    if (c == '+') {
        return 0;
    } else if (c == '-') {
        return 0;
    } else if (c == '*') {
        return 0;
    } else if (c == '/') {
        return 0;
    } else if (c == '\n') { //new line
        return 0;
    } else if (c == '\0') { //EOF
        return 0;
    } else { // Unknow token
        if (messageActivate != 0) {
            std::cout << "<!> Unknow Token" << std::endl;
        }
    }
    // lex to next char
    this->NextChar();
}

// void lexer::PushMessage (std::string message) {
//     if (messageActivate != 0) { //push message to serial window
//         std::cout << "TestingLoop: " << c << std::endl;
//     }
// }