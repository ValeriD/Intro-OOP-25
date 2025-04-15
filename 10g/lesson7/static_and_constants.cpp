#include<iostream>

using namespace std;

class Counter{
    const int id;
    int a;
    static int numberOfCounters;

public:
    Counter()
    : id(++numberOfCounters)
    {
        // numberOfCounters++;
    }

    ~Counter(){
        numberOfCounters--;
    }

    // Counter(int value)
    // :id(value)
    // {
    //     // this->id = id;
    //     // cout << a << endl;
    //     // this->a = id;
    //     // cout << a << endl;
    // }

    int getId() const {
        return this->id;
    }

    static int getNumberOfCounters() {
        return numberOfCounters;
    }

};

int Counter::numberOfCounters = 0;



int main(){
    // cout << Counter::getNumberOfCounters() << endl;
    
    Counter c;
    cout << c.getId() << endl;
    cout << c.getNumberOfCounters() << endl;
    
    // c.numberOfCounters = 1;

    Counter c2;
    cout << c2.getId() << endl;
    cout << c2.getNumberOfCounters() << endl;
    

    // const int a = 1;
    // a = 2;

    // const int* arr = new int[10];
    // arr[0] = 1;
    // arr = new int[5];

    // int *const arr1 = new int[10];
    // arr1[0] = 1;
    // arr1 = new int[5];

    // const int *const arr2 = new int[10];
    // arr2[0] = 1;
    // arr2 = new int[5];

    return 0;
}