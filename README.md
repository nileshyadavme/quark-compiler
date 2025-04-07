# ⚛️ Quark Compiler

> A tiny compiler written in modern C++ with an x86 Assembly backend.  

---

## 🚀 Overview

**Quark** is a small compiler I'm building in C++ as part of my compiler design course. It's meant to be simple, modular, and easy to understand.

I’m writing all the phases from scratch—no Flex, no Bison, no LLVM. Just raw C++, hand-written lexers, and assembly in the backend. It’s a learning project, so the goal is clarity over complexity.

If you’re also into systems programming or just curious how compilers work under the hood, this might be interesting to you.

---

## 🔩 Features

- 🧱 Lexical Analyzer — Tokenizes raw input into meaningful symbols  
- 🌲 Recursive-Descent Parser (WIP) — Builds ASTs from token streams  
- 🧠 Semantic Analyzer (Planned) — Scope & type checking  
- 🧬 Intermediate Representation (Planned) — Custom IR generation  
- 🛠 x86 Backend — Emits low-level NASM-style assembly  
- 🔧 Modular Codebase — Organized into components: lexer, token, utils, etc.  
- 🧰 Header-Only Utilities — File I/O, string ops, and more  

---

## 🗂️ Project Structure

```
quark/
├── include/
│   └── quark/
│       ├── fileutils/
│       │   └── FileUtil.h
│       ├── lexer/
│       │   └── Lexer.h
│       ├── token/
│       │   └── Token.h
│       └── common/
│           └── Utils.h
│
├── src/
│   ├── fileutils/
│   │   └── FileUtil.cpp
│   ├── lexer/
│   │   └── Lexer.cpp
│   ├── token/
│   │   └── Token.cpp
│   └── common/
│       └── Utils.cpp
│
├── test/
│   └── hello.qk
│
├── main.cpp
├── CMakeLists.txt
└── README.md
```

---

## 🛠️ Build Instructions

### 📦 Requirements

- C++17 or later  
- CMake ≥ 3.16  
- NASM (optional for backend testing)

### 🔧 Building with CMake

```bash
git clone https://github.com/your-username/quark.git
cd quark
mkdir build && cd build
cmake ..
make
./quark ../test/hello.qk
```

### 💡 Running in CLion

1. Open the project in CLion  
2. Go to Run > Edit Configurations  
3. Add `../test/hello.qk` as program argument  
4. Click Run or press Shift+F10  

---

## 🔍 Example `.qk` Code

```qk
print("Hello, world!");

let x = 42;
let y = x * 2;

if (y > 50) {
    print("Big!");
}
```

---

## 📈 Roadmap

| Feature                | Status        |
|------------------------|---------------|
| File I/O Utilities     | ✅ Complete    |
| Token Type System      | ✅ Complete    |
| Lexer                  | ✅ Complete    |
| Parser                 | 🔄 In Progress |
| Semantic Analysis      | ⏳ Planned     |
| Intermediate Codegen   | ⏳ Planned     |
| x86 Backend            | 🔄 In Progress |
| Optimizations          | ⏳ Optional    |
| Examples & Docs        | 🔄 Ongoing     |

---

## 🤝 Contributing

This is currently a solo-built compiler, but contributions, ideas, and collaborations are welcome.

To contribute:

1. Fork the repo  
2. Create a new branch  
3. Submit a pull request or open an issue for discussion

---

## 👤 Author

**Nilesh Kumar Yadav**  
Computer Science Undergraduate
[GitHub](https://github.com/nileshyadavme)

