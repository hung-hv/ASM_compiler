#include <iostream>
#include <string>

class lexer
{
private:
    /* data */
    int messageActivate = 1;
    char* curChar = NULL;
    int curPos = 0;
    int sourceSize;
    // std::string source;

public:
    // char* demo = "this is test";
    char* c_source;
    std::string s_source;
    lexer(/* args */);
    ~lexer();

    //method
    char NextChar(); //parse to next char in lexer source
    char PeekChar(); //peek next char in lexer source but not inscrease curPos
    int getSrouce(std::string source);
    void TestingLoop();
    int isToken();
};

