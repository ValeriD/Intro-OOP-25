#include<iostream>

using namespace std;

class Parent{
    int b;
public:
    int a;

    Parent(){
        cout<< "Hello from parent constructor" << endl;
    }

    Parent(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }

    ~Parent(){
        cout << "Hello from parent destructor" << endl;
    }

    int getB() const {
        return b;
    }
protected:
    int c;

    
};

class Child : public Parent {
public:

    Child()
    : Parent(1,2,3)
    {
        cout << "Hello from child constructor" << endl;
        // this->a = 1;
        // this->c = 3;
    }

    Child(const Child& other)
    : Parent(other)
    {

    }

    Child& operator=(const Child& other)
    {
        Parent::operator=(other);
        return *this;
    }

    ~Child() {
        cout << "Hello from child destructor" << endl;
    }

    int getA() const {
        return a;
    }

    int getC() const {
        return c;
    }
};

int main(){


    Child c;


    cout << c.getA() << endl;
    cout << c.getB() << endl;
    cout << c.getC() << endl;
    return 0;
}