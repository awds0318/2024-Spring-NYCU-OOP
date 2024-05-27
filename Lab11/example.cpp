#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Some animal sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak() override
    {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak() override
    {
        cout << "Meow!" << endl;
    }
};

void makeAnimalSpeak(Animal *animal)
{
    animal->speak();
}

int main()
{
    Animal *myDog = new Dog();
    Animal *myCat = new Cat();

    makeAnimalSpeak(myDog); // Outputs: Woof!
    makeAnimalSpeak(myCat); // Outputs: Meow!

    delete myDog;
    delete myCat;

    return 0;
}
