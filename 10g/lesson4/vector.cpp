#include <iostream>

using namespace std;
int ERROR = 2147483647;

class Vector{
    size_t size;
    size_t capacity;
    int* data;

    void resize(){
        this->capacity*=2;
        int* newData = new int[this->capacity];
        for(size_t i = 0; i<this->size; i++){
            newData[i] = this->data[i];
        }

        delete [] this->data;
        this->data = newData;
    }

public:

    Vector(){
        this->size = 0;
        capacity = 2;
        data = new int[capacity];
    }

    ~Vector(){
        delete[] this->data;
    }
    // Vector(size_t capacity){
    //     this->capacity = capacity;
    // }

    void pushBack(int value){
        if(this->size == this->capacity){
            resize();
        }
        this->data[size] = value;
        this->size++;
    }

    

    void print(){

    }

    int pop() {
        // if(this->size == 0 ) return ERROR;
        // int result = this->data[this->size-1];
        // this->size--;
        // return result;
    
        // return this->data[--this->size];

        return (this->size) ? this->data[--this->size] : ERROR;
    }

    int at(size_t index){
        if(index >= this->size) return ERROR;
        return this->data[index];
    }

};

int main(){
 Vector v;
 
}