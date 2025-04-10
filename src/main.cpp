// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-10 02:04
// 📄 File        : main.cpp
// 📝 Description : Entry point
// ------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>

#include "lexer/lexer.h"
#include "utils/FileUtils.h"
using namespace quark;

int main() {
    // Read the source code
    std::string source = quark::io::readFileAsString("../test.qk");
    
    std::cout<<"SOURCE CONTENT"<<std::endl;
    // std::cout<<source<<std::endl;

    quark::Lexer lexer(source);
    lexer.scanAllTokens();

    lexer.printTokens(lexer.getTokens());

    // // Print tokens
    // for (const auto& token : tokens) {
    //     std::cout << tokenTypeToString(token.Type)
    //               << " : " << token.lexeme
    //               << " (line " << token.line << ")"
    //               << std::endl;
    // }

    return 0;
}
