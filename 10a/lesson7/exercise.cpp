#include<iostream>

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
        name = "";
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

};


int main() {

    return 0;
}