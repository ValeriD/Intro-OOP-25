#include<iostream>

using namespace std;
///////////////////////////////////
// Most important:
// A class is a blueprint for an object

// An object is an instance of a class
// - A a; - that is an instance
// - A* ptr = new A(); - that is also an instance

// The classes have properties and methods:
// - properties are variables
// - methods are functions

// The classes have visibility:
// - public - can be accessed from outside the class
// - private - can be accessed only from inside the class

// The classes have constructors and destructors:
// - constructor is a special method that is called when an object is created
// - destructor is a special method that is called when an object is destroyed
// - the constructor has the same name as the class and no return type

// Constructor can be triggered by the keyword new
// Destructor can be triggered by the keyword delete

// this keyword is a pointer to the object itself.
///////////////////////////////////

class A{
private:
int a = 0;

public:
    A() {
        cout << "Hello from default constructor" << endl;
        a = 5;
    }

    A(int value){
        cout << "Hello from constructor with params"<<endl;
        a = value;
    }

    ~A(){
        cout << "Hello from destructor" << endl;
    }
    int getA() const{
        return a;
    }

private:

public:

};

struct B {
    int a;
};

class C{
    
};

int main(){
    struct B b;
    A a;    // Default constructor
    A b(5); // Constructor with parameters

    cout << a.getA() << endl;  // Accessing a property via a method

    // Creating an object in a new scope to demonstrate the destructor
    {
        A a;
    }

    A *ptr = new A();    // Default constructor
    A *ptr2 = new A(60); // Constructor with parameters

    // If we don't call delete, the destructor will not be called
    delete ptr;  // Destructor
    delete ptr2; // Destructor

    return 0;
}