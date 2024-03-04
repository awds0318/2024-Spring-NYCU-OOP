## OOP

- **Lab0**：C++ Vscode IDE & GDB
    ```bash
    g++ example.cpp -o example.exe
    ./example.exe
    ```
    `iverilog` will conflict with the `g++` environment：

    `C:\iverilog\gtkwave\bin` `C:\iverilog\bin` <--> `C:\msys64\ucrt64\bin`

    To solve this, remove the `iverilog` environment variables, restart your computer, add them back, and restart again, then everything will be fine.

- **Lab1**：C++ Basics & Flow of Control

- **Lab2**：C++ Function Basics

    `g++ main.cpp func.cpp -o main` `./main`




