#include<iostream>
using namespace std;


/////////////////////////////////////////////////
// Constructors
/////////////////////////////////////////////////
// 1. Default constructor
// 2. Constructor with parameters
// 3. Copy constructor
// 4. Move constructor
/////////////////////////////////////////////////
// Overloaded operators
/////////////////////////////////////////////////
// Copy assign operator - operator=();

/////////////////////////////////////////////////
class B{
    int b;
public:
    B() {
        this->b = 0;
    }

    B (int b){
        cout << "Hello from constructor with params" << endl;
        this->b = b;
    }
    B(const B& other){
        cout << "Hello from copy constructor" << endl;
        this->b = other.b;
    }

    // B(const B& other) = delete;



    B& operator=(const B& other){
        cout << "Hello from operator= " << endl;
        this->b = other.b;
        return *this;
    }

    int getB() const{
        return this->b;
    }

    void setB(int b) {
        this->b = b;
    }
};

class Vector
{
    int *data;
    size_t size;
    size_t capacity;

public:
    Vector()
    {
        size = 0;
        capacity = 2;
        data = new int[capacity];
    }

    Vector(const size_t capacity)
    {
        this->capacity = capacity;
        data = new int[capacity];
    }

    ~Vector()
    {
        delete[] data;
    }

    Vector(const Vector& other){
        this->data = new int[other.capacity];
        for(size_t i = 0; i< other.size; i++){
            this->data[i] = other.data[i];
        }
        this->capacity = other.capacity;
        this->size = other.size;
    }

    Vector& operator=(const Vector& other){
        if(this != &other){
            delete[] this->data;
            
            this->data = new int[other.capacity];
            for(size_t i = 0; i< other.size; i++){
                this->data[i] = other.data[i];
            }
            this->capacity = other.capacity;
            this->size = other.size;
        }
        return *this;
    }

    size_t getCap() const
    {
        return capacity;
    }
};

int main(){
    // B b(2);

    // B b1 = b; // B b1(b) // Copy constructor

    // B b2;
    // b2 = b; // b2.operator=(b); // Copy assign operator

    Vector v(5);

    Vector v2(2);

    v2 = v; // Copy constructor

    v2 = v2; // Copy assign operator

    return 0;
}