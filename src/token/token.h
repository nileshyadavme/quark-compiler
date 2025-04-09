// ========================================
// Author      : Nilesh Kumar Yadav
// Created At  : 2025-04-10 00:28
// Description : 
// ========================================

#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include<iostream>
#include<string>

/*Enum representing all the possible token type for now!*/

namespace quark {
    enum class TokenType {
        // BRACKETS
        LB, RB,
        LS, RS,
        LC, RC,

        // TYPE SPECIFIER
        TYPE_VOID, TYPE_INT, TYPE_BOOL, TYPE_CHAR,

        // OPERATOR
        PLUS, MINUS, STAR, SLASH, // +, -, *, /
        EQUAL, EQUAL_EQUAL, // =, ==
        BANG, BANG_EQUAL, // !, !=
        GREATER, GREATER_EQUAL, // >, >=
        SMALLER, SMALLER_EQUAL, // <,<=

        // Literals
        IDENTIFIER, STRING, NUMBER,

        // KEYWORDS
        LET, WHEN, OTHERWISE, REPEAT, SAY, TRUE, FALSE, EMPTY, DO, GIVE

        // SPECIAL
        // END_OF_FILE, UNKNOWN

        // Token structure
    };
    struct Token {
        TokenType Type;
        std::string lexeme;
        int line;
        Token(TokenType type, const std::string& lexeme, int line)
        : Type(type), lexeme(lexeme), line(line) {}
    };

    // == TokenType to string (for debubbing) ===
    inline std::string tokenTypeToString(TokenType type){
        switch (type)
        {
        // BRACKETS
        case TokenType::LB: return "LEFT_BRACKET";
        case TokenType::RB: return "RIGHT_BRACKET";
        case TokenType::LS: return "LEFT_SQUARE";
        case TokenType::RS: return "RIGHT_SQUARE";
        case TokenType::LC: return "LEFT_CURLY";
        case TokenType::RC: return "RIGHT_CURLY";
        
        // TYPE SPECIFIER
        case TokenType::TYPE_VOID: return "TYPE_BOID";
        case TokenType::TYPE_INT: return "TYPE_INT";
        case TokenType::TYPE_CHAR: return "TYPE_CHAR";
        case TokenType::TYPE_BOOL: return "TYPE_BOOL";

        // OPERATOR
        case TokenType::PLUS: return "PLUS";
        case TokenType::MINUS: return "MINUS";
        case TokenType::STAR: return "STAR";
        case TokenType::SLASH: return "SLAHS";
        case TokenType::EQUAL: return "EQUAL";
        case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
        case TokenType::BANG: return "BANG";
        case TokenType::BANG_EQUAL: return "BANG_EQUAL"; 
        case TokenType::GREATER: return "GREATER";
        case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
        case TokenType::SMALLER: return "SMALLER";     
        case TokenType::SMALLER_EQUAL: return "SMALLER_EQUAL";
        
        // Literals     
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::STRING: return "STRING";
        case TokenType::NUMBER: return "NUMBER";
        
        // KEYWORDS
        case TokenType::LET: return "LET";
        case TokenType::WHEN: return "WHEN";
        case TokenType::OTHERWISE: return "OTHERWISE";
        case TokenType::REPEAT: return "REPEAT";
        case TokenType::SAY: return "SAY";
        case TokenType::TRUE: return "TRUE";
        case TokenType::FALSE: return "FALSE";
        case TokenType::EMPTY: return "EMPTY";
        case TokenType::DO: return "DO";
        case TokenType::GIVE: return "GIVE";
        

        default: return "UNKNOWN";
        }
    }
}

#endif //TOKEN_H
