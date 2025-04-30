#include<iostream>
#include<vector>

using namespace std;

class Animal{
    //breed?
    string name;
    unsigned legs;
    unsigned age;
    double weight;
    bool isHungry;

public:
    Animal(){
        name = "Default name";
        age = 0;
        weight = 0;
        isHungry = false;
        legs = 0;
    }

    Animal(const string& name, unsigned age, double weight)
    : name(name), age(age), weight(weight), isHungry(true), legs(4)
    {
        if(name.empty()){
            throw invalid_argument("");
        }
        if(weight <= 0){
            throw invalid_argument("");
        }
    }

    virtual void sayHello() const {
        cout << "Hello from animal" << endl;
    }

    virtual void sayBye() const = 0;

    void getName() const {
        cout << this->name << endl;
    }
};

enum DogBreed {
    LAB, HUSKY, STAFFY
};

class Dog : public Animal{
    int barkingScale; //
    DogBreed breed;
public:
    Dog(){

    }

    Dog(string name, DogBreed breed, unsigned age, double weight, int barkingScale)
    : Animal(name, age, weight), breed(breed), barkingScale(barkingScale)
    {
        if(barkingScale <= 0 ){
            throw invalid_argument("");
        }
    }
    void sayHello() const override{
        cout << "Hello from dog" << endl;
    }
    void sayBye() const override {
        cout << "Goodbye from dog" << endl;
    }
};

enum CatBreed{};

class Cat : public Animal{
    CatBreed breed;
    bool hasParasites;
    int lives;
public:
    Cat(){

    }

    Cat(string name, CatBreed breed, unsigned age, double weight)
    : Animal(name, age, weight), lives(9), hasParasites(false)
    {}
    void sayHello() const override{
        cout << "Hello from cat" << endl;
    }
    void sayBye() const override {
        cout << "Goodbye from cat" << endl;
    }
};


int main() {
    // Demonstrate polymorphism
    Animal** animals = new Animal*[10];

    Cat cat;
    Dog dog;
    

    animals[0] = &cat;
    animals[1] = &dog;
    animals[2] = new Cat();
    animals[3] = new Dog();

    animals[0]->sayHello();
    animals[1]->sayHello();
    
    delete animals[2];
    delete animals[3];
    delete []animals;
    
    // Demonstrate vector usage
    vector<Animal*> animals1; // Animal* animals = new Animals[10];
    animals1.push_back(&dog);
    animals1.push_back(&cat);

    // For each in cpp
    for(auto animal: animals1){
        animal->sayHello();
    }

    // animals1[0].sayHello();
    // animals1[1].sayHello();

    // Demonstrate that a default constructor is called when allocating a dynamic array
    // Animal* animals2 = new Animal[10];
    // animals2[0] = cat;
    // animals2[1] = dog;
    // animals2[2].getName();
    return 0;
}