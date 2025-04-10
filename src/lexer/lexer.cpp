// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-10 00:39
// 📄 File        : lexer.cpp
// 📝 Description : implementation of lexer.h
// ------------------------------------------

#include "lexer.h"
#include<cctype>

quark::Lexer::Lexer(std::string &source)
{
    this->content = source;
}

bool quark::Lexer::isAtEnd()
{
    return current >= content.length();
}

char quark::Lexer::advance()
{
    return content[current++];
}

char quark::Lexer::peek()
{
    return content[current];
}

char quark::Lexer::peekNext()
{
    return content[current++];
}

void quark::Lexer::skipWhiteSpace()
{
    while(!isAtEnd())
    {
        char c = peek();
        switch (c)
        {
            case ' ':
            case '\r':
            case '\t':
                advance();
                break;
            case '\n':
                line++;
                advance();
                break;
            default:
                return;
        }
    }
}

void quark::Lexer::addToken(TokenType type, std::string lexeme, int line)
{
    tokens.emplace_back(type, lexeme, line);
}

bool quark::Lexer::identifier() {
    int start = current - 1;

    while (!isAtEnd() && (isalnum(peek()) || peek() == '_')) {
        advance();
    }

    std::string text = content.substr(start, current - start);

    // Check if it's a keyword
    if (text == "say") {
        addToken(TokenType::SAY, text, line);
    } else if (text == "when") {
        addToken(TokenType::WHEN, text, line);
    } else if (text == "otherwise") {
        addToken(TokenType::OTHERWISE, text, line);
    } else if (text == "true") {
        addToken(TokenType::TRUE, text, line);
    } else if (text == "false") {
        addToken(TokenType::FALSE, text, line);
    } else {
        // Otherwise, it’s a regular identifier
        addToken(TokenType::IDENTIFIER, text, line);
    }

    return true;
}


void quark::Lexer::scanToken() {
    skipWhiteSpace();
    if (isAtEnd()) return;

    char c = advance();
    if (isalpha(c)) {
        identifier();
    } else if (isdigit(c)) {
        number();
    } else if (c == '"') {
        string();
    } else {
        switch (c) {
            case ';': addToken(TokenType::SEMICOLON, ";", line); break;
            case '(': addToken(TokenType::LEFT_PAREN, "(", line); break;
            case ')': addToken(TokenType::RIGHT_PAREN, ")", line); break;
            // ... add more symbols
            default:
                std::cerr << "Unexpected character at line " << line << ": " << c << "\n";
                break;
        }
    }
}

void quark::Lexer::printTokens(const std::vector<Token>& tokens) {
    for (const auto& token : tokens) {
        std::cout << tokenTypeToString(token.type) << " : " << token.lexeme << " @ line " << token.line << "\n";
    }
}

bool quark::Lexer::number() {
    int start = current - 1;

    while (!isAtEnd() && isdigit(peek())) advance();

    // Check for fractional part
    if (!isAtEnd() && peek() == '.' && isdigit(peekNext())) {
        advance(); // consume '.'
        while (!isAtEnd() && isdigit(peek())) advance();
    }

    std::string text = content.substr(start, current - start);
    addToken(TokenType::NUMBER, text, line);
    return true;
}

const std::vector<quark::Token>& quark::Lexer::getTokens() const {
    return tokens;
}
void quark::Lexer::scanAllTokens() {
    while (!isAtEnd()) {
        scanToken();
    }
}
bool quark::Lexer::string() {
    int start = current;

    while (!isAtEnd() && peek() != '"') {
        if (peek() == '\n') line++;
        advance();
    }

    if (isAtEnd()) {
        std::cerr << "Unterminated string at line " << line << "\n";
        return false;
    }

    advance(); // consume closing "

    std::string value = content.substr(start, current - start - 1);
    addToken(TokenType::STRING, value, line);
    return true;
}
