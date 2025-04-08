#include<iostream>

using namespace std;

class Parent{
    int a;
public:
    // Parent(){
    //     cout << "Hello from parent constructor" << endl;
    // }
    Parent(int a, int b, int c){
        cout << "Hello from parent constructor" << endl;
        this->a = a;
        this->b = b;
        this->c = c;
    }
    ~Parent(){
        cout << "Hello from parent destructor" <<endl;
    }
    
    int c;
protected:
    int b;
    int getValueOfA() const{
        return this->a;
    }
};

class Child : public Parent {
public:
    Child()
    : Parent(1,2,3)
    {
        cout << "Hello from child constructor"<<endl;
    }
    ~Child(){
        cout << "Hello from child destructor" << endl;
    }


    Child(const Child& other)
    : Parent(other)
    {

    }

    Child& operator=(const Child& other){
        Parent::operator=(other);
        if(this != &other){

        }
        return *this;
    }
    int getA() const{
        return this->getValueOfA();
    }

    // int getValueOfA() const{
    //     return Parent::getValueOfA();
    // }
    
    int getB() const {
        return this->b;
    }

    int getC() const {
        return this->c;
    }
};

class GrandChild: public Child{

};

int main() {
    Child c;

    cout << c.c << endl;
    cout << c.getB() << endl;
    return 0;
}
