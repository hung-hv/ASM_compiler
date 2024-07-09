#include "lexer.hpp"
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
    std::cout << "NextChar: " << c << std::endl;
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
        std::cout << "-> source added" << std::endl;
        return 1; //success
    }
}

void lexer::TestingLoop() {
    char c;
    while (c != '\0') {
        c = this->NextChar();
        std::cout << "TestingLoop: " << c << std::endl;
    }
}
