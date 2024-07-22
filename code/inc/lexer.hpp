#include <iostream>
#include <string>
#include "Token.hpp"

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
    // Token eToken; //instance of token

    //method
    char NextChar(); //parse to next char in lexer source
    char PeekChar(); //peek next char in lexer source but not inscrease curPos
    int getSrouce(std::string source);
    void TestingLoop();
    Token::Token_t GetToken(); // Add the missing type definition for Token_t
    void SkipWhiteSpace();
};

