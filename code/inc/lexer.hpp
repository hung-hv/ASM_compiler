#include <iostream>

class lexer
{
private:
    /* data */
    
    char* curChar = NULL;
    int curPos = 0;

public:
    char* demo = "this is test";
    lexer(/* args */);
    ~lexer();
    char NextChar(); //parse to next char in lexer source
};

