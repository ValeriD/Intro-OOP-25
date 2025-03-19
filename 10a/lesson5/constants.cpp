#include<iostream>

using namespace std;

class A {

    const int a;
    // int a;
    int* b;

    public:

    A(int value)
    : a(value), b(new int[value])
    {
        // cout << this->a << endl;
        // this->a = a;
    }

    int getA()const {
        return this->a;
    }
};

int main(){
    // const int a = 1;

    // const int *arr = new int[2];
    // arr = new int[5];
    // arr[0] = 1;

    // int *const arr1 = new int[2];
    // arr1[0] = 1;
    // arr1 = new int[3]; // Error

    // const int * const arr2 = new int[2];
    // arr2[0] = 1;
    // arr2 = new int[3];


    A a(5);

    return 0;
}