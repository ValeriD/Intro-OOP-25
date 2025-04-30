#include<iostream>
#include <cstring>

using namespace std;

class Person {
protected:
    char* name;
    unsigned age;
    int weight;
    int height;
    static int numberOfPeople;
public:
    Person(char* name, int age, int weight, int height)
    {
        this->name = strdup(name);
        this->age = age;
        this->weight = weight;
        this->height = height;
        numberOfPeople++;
    }

    ~Person(){
        numberOfPeople--;
    }

    Person (const Person& other){
        this->name = strdup(other.name);
        this->age = other.age;
        this->weight = other.weight;
        this->height = other.height;
        numberOfPeople++;
    }

    void printInfo(){
        
        cout << "=================================" << "\n"
            << "Name: " << this->name << "\n"
            << "Age: " << this->age << "\n"
            << "Weight: " << this->weight << "\n"
            << "Height: " << this->height << "\n"
            << "================================="
            << endl; 
    }

    void doSport() {
        cout << "I don't play anything" << endl;
    }

    static int getNumberOfPeople() {
        return numberOfPeople;
    }
};

int Person::numberOfPeople = 0;

class FootballPlayer : public Person {
public:
    FootballPlayer(char* name, int age, int weight, int height)
    : Person(name, age, weight, height)
    {
    }

    void doSport() {
        Person::doSport();
        cout << "I play football" << endl;
    }

    void shoot() {
        cout << "Goal" << endl;
    }
};

class BasketballPlayer : public Person{
    
public:
    BasketballPlayer(char* name, int age, int weight, int height)
    : Person(name, age, weight, height)
    {
    }

    void doSport() {
        cout << "I play basketball" << endl;
    }
};

class BaseballPlayer : public Person {
    int batLength;
public:
    BaseballPlayer(char* name, int age, int weight, int height)
    : Person(name, age, weight, height)
    {
        this->batLength = 70;
    }

    void doSport(){
        cout << "I play baseball" << endl;
    }

    void strike() {
        cout << "Strike!" << endl;
    }

    void printInfo(){
        cout << "=================================" << "\n"
            << "Name: " << this->name << "\n"
            << "Age: " << this->age << "\n"
            << "Weight: " << this->weight << "\n"
            << "Height: " << this->height << "\n"
            << "Bat length: " << this->batLength << "\n"
            << "================================="
            << endl; 
    }
};

int main(){

    // Person p("Gosho", 20, 80, 189);
    // p.doSport();
    
    // cout << "----------------------------------------"<<endl;
    // FootballPlayer fp("Ronaldo", 40, 89, 190);
    // fp.doSport();
    // cout << "----------------------------------------"<<endl;

    BaseballPlayer baseP("Gosho", 20, 80, 189);
    baseP.printInfo();

    Person p2 = baseP;
    p2.printInfo();

    // BaseballPlayer baseP2 = p2; // Invalid unless explicitly defined

    cout << Person::getNumberOfPeople() << endl;


    // string s = "Gosho";
    // s.empty();
    // s.c_str(); // Returns char*
    // s == "" ? cout << true << endl : cout << false << endl;

    // s.append("asd");
    return 0;
}