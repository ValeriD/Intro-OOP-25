#include<iostream>

using namespace std;

class A {
   unsigned int a;
    string name;
public:
    A (){
        a = 1;
        name = "Gosho";
    }

    void setA(int value) {
        if(value < 0 ) throw invalid_argument("");
        this->a = value; 
    }

    unsigned getA() const{
        return this->a;
    }

    const string& getName() const{
        return this->name;
    }
};

void f1(string& str){
    str[0] = 't';
}

void f2(string* s){
    (*s)[1] = 'E';
}

int main(){

    // const A object;
    // // object.setA(-1);
    // cout << object.getA() << endl;

    // string s = "Test";
    // try{
    //     f1(s);
    //     f2(nullptr);

    // }catch(const exception& e){

    // }
    // cout << s << endl;

    A object;
    // object.getName() = "Tosho";
    cout << object.getName() << endl;
    string test = "Test";
    string& test1 = test;
    test[0] = 't';
    cout << test1 << endl;
    
    return 0;
}