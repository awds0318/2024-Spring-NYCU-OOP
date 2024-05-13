#include <iostream>
using namespace std;

struct A
{
    A() { cout << "ctorA" << endl; }
    ~A() { cout << "dtorA" << endl; }
};

struct B
{
    B() { cout << "ctorB" << endl; }
    ~B() { cout << "dtorB" << endl; }
};

struct C : public B
{
    A a;
    // C() { cout << "ctorC" << endl; }
    // C() : a(), B() { cout << "ctorC" << endl; }
    C() : B(), a() { cout << "ctorC" << endl; }
    ~C() { cout << "dtorC" << endl; }
};

int main()
{
    C c;

    return 0;
}

// * whenever comment line 19, 20 or 21, output result will stil remain same
// * output
// ctorB
// ctorA
// ctorC
// dtorC
// dtorA
// dtorB