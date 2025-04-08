//
// Created by conta on 08-04-2025.
//
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
        END_OF_FILE, UNKNOWN
    };
}

#endif //TOKEN_H
