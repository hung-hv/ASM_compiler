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
}

lexer::~lexer()
{
    
    // free(this->demo);
    free(this->curChar);
}

char lexer::NextChar()
{
    this->curPos++;
    this->curChar = this->demo + this->curPos;
    char c = *(this->curChar);
    std::cout << "NextChar: " << c << std::endl;
    return c;
}

