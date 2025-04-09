// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-10 00:38
// 📄 File        : main.cpp
// 📝 Description : 
// ------------------------------------------

#include <iostream>
#include "utils/FileUtils.h"

int main(int argc, char* argv[]) {
    if (argc<2) {
        std::cerr << "usage : quark <input.qk>\n";
        return 1;
    }
    const std::string filePath = argv[1];
    try {
        std::string content = quark::io::readFileAsString(filePath);
        std::cout << "File Content\n"<<content<<"\n";
        for (int i=0;i<content.size();i++) {
            std::cout<<content[i]<<" ";
        }

    } catch (const std::exception &e) {
        std::cerr<<"error : "<<e.what()<<std::endl;
    }
    return EXIT_SUCCESS;
}
