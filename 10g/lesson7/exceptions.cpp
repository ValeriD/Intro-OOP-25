#include<iostream>
#include<exception>

using namespace std;

class A {
    int a;
public:
    A(){
        a = 1;
    }
    int getA()const {
        return this->a;
    }

    void setA(int value){
        // a >= 0
        if(value < 0) throw invalid_argument("The value must be positive");
        if(value == 0) throw runtime_error("Cannot be zero");
        if(value == 1) throw exception();
        this->a = value;
    }
};

void readInput(A& object){
    int a;
    cin >> a;
    // try{
        object.setA(a);
    // }
   
    // catch(exception& e){
    //     cout << e.what() << endl;
    // }
}

int main(){
    A object;
    cout << object.getA() << endl;
    int a;
    cin >> a;
    try{
        object.setA(a);
    } catch(runtime_error& e){
        cout << "Warning: " << e.what() << endl;
    }
    catch(invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
    // int result = object.setA(-1);
    // if(result == -1) cout << "Error: tried to assign negative number" << endl;
    cout << object.getA() << endl;
    object.setA(5);
    cout << object.getA() << endl;
    return 0;
}