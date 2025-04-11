#include<iostream>
#include<cstring>

using namespace std;

// DRY - don't repeat yourself

class Car {
protected:
    char* model;
    unsigned int year;
    unsigned int horsepower;
    double zeroToHundred;

    void copy(const Car& other){
        this->model = strdup(other.model);
        this->year = other.year;
        this->horsepower = other.horsepower;
        this->zeroToHundred = other.zeroToHundred;
    }
public:
    Car(const char* model, unsigned year, int horsepower, double zeroToHundred){
        if(model == nullptr || strcmp(model, "") == 0) throw invalid_argument("Make is empty");

        if(zeroToHundred <= 0) throw invalid_argument("Zero to hundred must be positive");

        if(horsepower <= 0) throw invalid_argument("Horsepower must be positive");

        if(year <= 1850) throw invalid_argument("Year must be later than the first car ever produced");

        this->year = year;
        this->horsepower = horsepower;
        this->zeroToHundred = zeroToHundred;

        // this->model = new char[strlen(model) + 1];
        // strcpy(this->model, model);

        this->model = strdup(model);
    }

    ~Car(){
        delete[] this->model;
    }

    Car(const Car& other){
       copy(other);
    }

    Car& operator=(const Car& other){
        if(this != &other){
            delete[] this->model;
            copy(other);
        }

        return *this;
    }

    const char* getModel() const {
        return this->model;
    }

    unsigned getYear() const{
        return this->year;
    }

    unsigned getHorsepower() const {
        return this->horsepower;
    }

    double getZeroToHundred() const
    {
        return this->zeroToHundred;
    }
};

class SportsCar : public Car{
    char* variation;
public:
    SportsCar(const char* model, const char* variation, unsigned year, unsigned horsepower, double zeroToHundred)
    : Car(model, year, horsepower, zeroToHundred) 
    {
        if(variation == nullptr || !strcmp(variation, "")) throw invalid_argument("");
        
        this->variation = strdup(variation);
    }

    ~SportsCar(){
        delete[] this->variation;
    }

    SportsCar(const SportsCar& other)
    : Car(other)
    {
        this->variation = strdup(other.variation);
    }

    SportsCar& operator=(const SportsCar& other) 
    {
        Car::operator=(other);
        if(this != &other){
            delete[] this->variation;
            this->variation = strdup(other.variation);
        }
        return *this;
    }

    const char* getVariation()const{
        return this->variation;
    }
};

class Limo {};

class Truck {};


int main() {

    SportsCar car("Honda", "Civic Type R", 2024, 300, 4.5);
    SportsCar car2("BMW", "M3 competition",2024, 650, 3.5);

    car = car2;

    Car car3(car2); // Car car3 = car2;

    // SportsCar car4 = car3;

    cout << car.getModel() << " " << car.getVariation() << " " << car.getYear() << " "  << car.getHorsepower() << " " << car.getZeroToHundred() << endl;
    cout << car3.getModel() << " " << car3.getYear() << " "  << car3.getHorsepower() << " " << car3.getZeroToHundred() << endl;

    // car2::~Car();
    // car3::~Car();
    return 0;
}