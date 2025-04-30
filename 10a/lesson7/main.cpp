#include<iostream>


using namespace std;

class A{
    unsigned int var;

    string a;
public:

    A(){
        var = 0;
    }

    void setVar(int value) {
        if(value < 0){
            throw invalid_argument("Must be positive");
        }
        this->var = value;
    }

    const string& getA()const {
        return this->a;
    }

    unsigned getVar() const {
        return this->var;
    }
};

void f1(string& a) {
    a[0] = 't';
}

void f2(string& a){
    a[1] = 'E';
}
void f3(string* a){
    a[0] = 'e';
}

int main() {
    // const A object;
    // object.getA();

    // object.getVar();

    // string a = "Test";
    // f1(a);
    // f2(a);
    // f3(&a);
    // cout << a << endl;

    A object;
    cout << object.getA() << endl;
    // object.getA() = "Test";
    cout << object.getA() << endl;
    return 0;
}