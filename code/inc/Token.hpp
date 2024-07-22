#ifndef TOKEN_H
#define TOKEN_H
class Token {
public:
    Token();
    enum TokenType {
        UNKNOW = -2,
        EOFILE = -1,
        NEWLINE = 0,
        NUMBER = 1,
        IDENT = 2,
        STRING = 3,
        // # Keywords.
        LABEL = 101,
        GOTO = 102,
        PRINT = 103,
        INPUT = 104,
        LET = 105,
        IF = 106,
        THEN = 107,
        ENDIF = 108,
        WHILE = 109,
        REPEAT = 110,
        ENDWHILE = 111,
        // # Operators.
        EQ = 201,
        PLUS = 202,
        MINUS = 203,
        ASTERISK = 204,
        SLASH = 205,
        EQEQ = 206,
        NOTEQ = 207,
        LT = 208,
        LTEQ = 209,
        GT = 210,
        GTEQ = 211,
    };

    typedef struct Token_t {
        char* textToken;
        TokenType kindToken;
    } Token_t;

    Token_t TokenObj;

    Token_t CreateToken(char c_char, TokenType token_type);
    Token_t CreateToken(char* c_text, int c_size, TokenType token_type);
    // ~Token();


private:
    // typedef struct Token_t {
    //     char *textToken;
    //     TokenType kindToken;
    // } Token_t;
};

#endif // TOKEN_H