# OOP

## **Lab0：C++ Vscode IDE & GDB**

```bash
g++ example.cpp -o example.exe
./example.exe
```

`iverilog` will conflict with the `g++` environment：

`C:\iverilog\gtkwave\bin` `C:\iverilog\bin` <--> `C:\msys64\ucrt64\bin`


To solve this, remove the `iverilog` environment variables, restart your computer, add them back, and restart again, then everything will be fine.

## **Lab1：C++ Basics & Flow of Control**

## **Lab2：C++ Function Basics & Purpose and Importance of Header Files**

For small programs, basically we only need to compile all the original files together to generate the required executable file. But what if it’s a large-scale project? Many programs are bound to be designed in the direction of modularization and high reusability. The most critical one is reusability, so for the sake of reusability, we put these pre-declarations into the header file. In this way, whether it is a dynamic library or a static link, we can reuse the library by including this header file.

**How to compile multiple files?**

- Method1:
```bash
g++ main.cpp func.cpp -o main

./main    
```

- **Method2 (prefered)**:
```bash
g++ -c main.cpp // generate main.o
g++ -c func.cpp // generate func.o
g++ main.o func.o -o main

./main
```

## **Lab3：C++ Array Transpose & Multiplication**

## **Lab4：C++ Structure & Class (LIFO : Last in First out)**

## **Lab5：C++ Constructors & Operator Overloading**

## **Lab6：C++ Constructors & Operator Overloading**

## **Lab7：C++ String**

## **Lab8：C++ Pointers and Dynamic Arrays**

## **Lab9：C++ Streams and File I/O**

`#include <map>`
> map like the dictionary in python, and it will auto sort itself.

`#include <vector>`
> we can implement `list.append` with using `vector.push_back`.

## **Lab10：C++ Inheritance**

## **Lab11：C++ Polymorphism and Virtual Functions**
