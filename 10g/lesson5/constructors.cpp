#include<iostream>

using namespace std;


class A{
    int a;
    // A(const A& other){}

public:
    A() 
    {
        a = 5;
    }

    A(const A& other){
        cout << "Hello from copy constructor" << endl;
        this->a = other.a;
    }

    A& operator=(A& other){
        cout << "Hello from Assign operator" << endl;
        if(this != &other){
            this->a = other.a;
        }
        return *this;
    }

    int getA() const {
        return this->a;
    }

};


class Vector{
    size_t size;
    size_t capacity;
    int* data;
public:

    Vector(){
        this->capacity = 2;
        this->data = new int[this->capacity];
        this->size = 0;
    }

    ~Vector(){
        delete [] this->data;
    }

    Vector(const Vector& other){
        this->capacity = other.capacity;
        this->size = other.size;
        this->data = new int[other.capacity];

        for(size_t i = 0; i < other.size; i++){
            this->data[i] = other.data[i];
        }

    }

    Vector& operator=(const Vector& other){
        if(this != &other){
            delete [] this->data;
            this->capacity = other.capacity;
            this->size = other.size;
            this->data = new int[other.capacity];

            for(size_t i = 0; i < other.size; i++){
                this->data[i] = other.data[i];
            }
        }

        return *this;
    }

};

int main(){

    // A object1;
    // cout << object1.getA() << endl;

    // A object2 = object1; // A object2(object1)
    // cout << object2.getA() << endl;

    // A object3;
    // object3 = object1; // object3.operator=(object1);
    // object3 = object3;

    Vector v;
    Vector v2;
    v2 = v;
    v2 = v2;
    return 0;
}