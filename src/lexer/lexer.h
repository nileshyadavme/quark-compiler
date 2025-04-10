// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-10 00:38
// 📄 File        : lexer.h
// 📝 Description : responsible for breaking source into tokens
// ------------------------------------------

#pragma once

#ifndef LEXER_H
#define LEXER_H

#include<string>
#include<vector>
#include "../token/token.h"

namespace quark {
    class Lexer {
    public:
        void printTokens(const std::vector<Token>& tokens);
        Lexer(std::string &source);
        std::vector<Token> tokens;
        void scanAllTokens();
        /* -- Core memeber function -- */
        void scanToken();
        const std::vector<Token>& getTokens() const;


    private:
        std::string content;
        
        /* -- DATA MEMBERS -- */
        int start = 0; // start of current lexeme
        int current = 0;// current scanning position
        int line = 1; // line number
        
        /* -- Control Helper -- */
        bool isAtEnd();
        char advance();
        char peek();
        char peekNext();
        bool match(char &c);
        

        /* -- Utilities -- */
        void skipWhiteSpace();
        void addToken(TokenType token, std::string lexeme, int line);
        

        /* -- Token Scanning Functions -- */
        bool string();
        bool number();
        bool identifier();
    };

}

#endif //LEXER_H

