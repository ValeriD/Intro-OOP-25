#include<iostream>
#include<vector>

using namespace std;

class Animal {
    string name;
    unsigned age;
    unsigned weight;

public:
    Animal() {
        name = "Default name";
        age = 0;
        weight = 0;
    }

    Animal(string _name, unsigned _age, unsigned _weight)
    : name(_name), age(_age), weight(_weight)
    {}

    void printName() const{
        cout << this->name << endl;
    }
    virtual void sayHello() const{
        cout << "Hello from Animal" << endl;
    }

    virtual void getAge() const = 0;
};

enum DogBreed{
    NONE, LAB, HUSKY
};

class Dog : public Animal{
    DogBreed db;
public:
    Dog() {
        db = DogBreed::NONE;
    }
    Dog(string name, DogBreed db, unsigned age, unsigned weight)
    : Animal(name, age, weight)
    , db(db)
    {
    }

    void sayHello() const override{
        cout << "Hello from Dog" << endl;
    }

    void  getAge() const override{
        cout << "7" << endl;
    }
};

class Cat : public Animal{

public:
    Cat(){

    }
    
    Cat(string name, unsigned age, unsigned weight) 
    : Animal(name, age, weight)
    {}

    void sayHello() const override {
        cout << "Hello from Cat" << endl;
    }
};


int main(){


    Animal** animals = new Animal*[10];
    // animals[5].printName();

    Dog d;
    Cat c;
    // animals[0] = &d;
    // animals[1] = &c;
    // d.sayHello();
    // c.sayHello();
    // animals[0]->sayHello();
    // animals[1]->sayHello();

    vector<Animal*> an;
    an.push_back(&d);
    an.push_back(&c);

    for(int i =0; i<an.size(); ++i){
        an[i]->sayHello();
    }

    for(auto animal: an){
        animal->sayHello();
    }


    // Animal* a = new Animal("Tosho", 1, 10);
    // Animal& refA = *a;
    // delete a;
    // refA.printName();

    // int a = 1;
    // int& b = a;

    // cout << a << endl;
    // cout << b << endl;

    // a = 2;

    // cout << a << endl;
    // cout << b << endl;

    return 0;
}