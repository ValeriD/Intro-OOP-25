#include<iostream>
#include<exception>

using namespace std;

int f1(int value){
    if(value <= 0){
        throw invalid_argument("The value must be positive");
        return -1;
    }

    return value;
}

int f2(int value){
    return f1(value) + 1;
}

int main(){
    try{
        f2(-5);
    }
    // catch(invalid_argument){

    // }
    catch(exception& e){
        cout << e.what() << endl;
        // main();
    }
    return 0;
}