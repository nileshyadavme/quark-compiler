// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-10
// 📄 File        : token.h
// 📝 Description : Simplified token types for minimal compiler
// ------------------------------------------

#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>

namespace quark {

    // === Token Types (Minimal) ===
    enum class TokenType {
        // Brackets
        LEFT_PAREN, RIGHT_PAREN,  // ( )
        LEFT_BRACE, RIGHT_BRACE,  // { }
        SEMICOLON, // ;

        // Operators
        EQUAL,        // =
        EQUAL_EQUAL,  // ==
        PLUS,         // +
        MINUS,        // -

        // Literals
        IDENTIFIER,
        STRING,
        NUMBER,
        TRUE,
        FALSE,

        // Keywords
        SAY,          // print
        WHEN,         // if
        OTHERWISE,    // else

        // End of source
        END_OF_FILE
    };

    // Token Structure
    struct Token {
        TokenType type;
        std::string lexeme;
        int line;

        Token(TokenType type, const std::string& lexeme, int line)
            : type(type), lexeme(lexeme), line(line) {}
    };

    // === Utility: TokenType to String (Debugging) ===
    inline std::string tokenTypeToString(TokenType type) {
        switch (type) {
            case TokenType::LEFT_PAREN: return "LEFT_PAREN";
            case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
            case TokenType::LEFT_BRACE: return "LEFT_BRACE";
            case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
            case TokenType::EQUAL: return "EQUAL";
            case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
            case TokenType::PLUS: return "PLUS";
            case TokenType::MINUS: return "MINUS";
            case TokenType::IDENTIFIER: return "IDENTIFIER";
            case TokenType::STRING: return "STRING";
            case TokenType::NUMBER: return "NUMBER";
            case TokenType::TRUE: return "TRUE";
            case TokenType::FALSE: return "FALSE";
            case TokenType::SAY: return "SAY";
            case TokenType::WHEN: return "WHEN";
            case TokenType::OTHERWISE: return "OTHERWISE";
            case TokenType::END_OF_FILE: return "END_OF_FILE";
            case TokenType::SEMICOLON: return "SEMICOLON";
            default: return "UNKNOWN";
        }
    }

} // namespace quark

#endif // TOKEN_H
