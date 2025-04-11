#include<iostream>

using namespace std;

class Vehicle{
    string regNumber;
    static int counter;

public:
    Vehicle(const string& regNumber){
        this->regNumber = regNumber;
        counter++;
    }

    ~Vehicle() {
        counter--;
    }

    const string& getRegNumber()const {
        return this->regNumber;
    }

    static int getCounter(){
        return counter;
    }

    // void setCounter(int value){
    //     this->counter = value;
    // }
};

int Vehicle::counter = 0;

int main(){

    Vehicle car("TX 7546 PC");
    Vehicle car2("TX 7646 PK");

    cout << Vehicle::getCounter() << endl;
    cout << car.getCounter() << endl;

    // car.counter = 5;

    // cout << Vehicle::counter << endl;
    // cout << car2.counter << endl;

    return 0;
}