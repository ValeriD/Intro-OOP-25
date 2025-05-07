#include<iostream>
#include<vector>


using namespace std;

enum Issuer{
    DSK, OBB, CKB
};

class Card {
    const string id;
    Issuer issuer;

public:
    Card(const string& _id, Issuer _is)
    :id(_id), issuer(_is) {}

    const string& getId() const;
    Issuer getIssuer() const;
};

class Shop{
protected:
    double cashBalance;
    double bankBalance;

    virtual double getCashCoef() = 0;
    virtual bool isCardSupported(Card& card) {
        return false;
    }
public:
    Shop(){
        cashBalance = 0;
        bankBalance = 0;
    }
    void payCash(double amount){
        cashBalance += getCashCoef() * amount;
    }

    virtual void payCard(Card& card, double amount){
        if(!isCardSupported(card)){
            throw invalid_argument("Card is unsupported");
        }

        bankBalance += amount;
    }
};

class LaptopShop : public Shop{

protected:
    double getCashCoef() override{
        return 0.9;
    }
    bool isCardSupported(Card& card) override {
        return card.getIssuer() == Issuer::DSK;
    }
public:
};

class PhoneShop : public Shop{

protected:
    double getCashCoef() override{
        return 0.85;
    }
    bool isCardSupported(Card& card) override {
        return card.getIssuer() == Issuer::OBB;
    }
public:
};

class GroceriesShop: public Shop{
protected:
    double getCashCoef() override{
        return 1.0;
    }

    // bool isCardSupported(Card& card) override {
    //     return false;
    // }
public:

    void payCard(Card& card, double amount) override{
        throw runtime_error("Method is unsupported");
    }
};

int main() {
    return 0;
}