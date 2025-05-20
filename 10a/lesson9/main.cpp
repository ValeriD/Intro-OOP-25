#include<iostream>

using namespace std;

enum CardIssuer {
    OBB, DSK, CKB
};

class Shop{
protected:
    double cashBalance;
    double bankBalance;

    virtual double getCoef() = 0;
    virtual bool isCardSupported(CardIssuer ci) = 0;
public:
    Shop(){
        cashBalance = 0;
        bankBalance = 0;
    }

    void payCash(double amount){ 
        if(amount <= 0){
            throw invalid_argument("Amount cannot be negative");
        }
        cashBalance += getCoef() *amount;
    }

    virtual void payCard(CardIssuer ci, double amount){
        if(!isCardSupported(ci)){
            throw invalid_argument("Card is unsupported");
        }
        bankBalance += amount;
    }
};

class LaptopShop : public Shop {


protected:
    double getCoef() override {
         return 0.9;
    }
    bool isCardSupported(CardIssuer ci) override {
        return ci == CardIssuer::OBB || ci == CardIssuer::DSK;
    }
};

class PhoneShop : public Shop {
protected:
    double getCoef() override {
        return 0.85;
    }
    bool isCardSupported(CardIssuer ci) override {
        return ci == CardIssuer::CKB || ci == CardIssuer::DSK;
    }
};

class GrocShop : public Shop {
public:
    double getCoef() override {
        return 1.0;
    }
    bool isCardSupported(CardIssuer ci) override {
        return false;
    }
public:
    void payCard(CardIssuer ci, double amount) override {
        throw runtime_error("Card payments are not supported");
    }
};


int main() {
    return 0;
}