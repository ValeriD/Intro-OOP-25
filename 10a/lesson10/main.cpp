#include<iostream>
#include<sstream>

using namespace std;

class Point {
    int x;
    int y;  
public:

    Point() {
        x = 0;
        y = 0;
    }

    void setX(int value) {
        this->x = value;
    } 

    void setY(int value){
        this->y = value;
    }

    void printPoint() const {
        cout << "("
        << x 
        << ","
        << y 
        << ")"
        << endl;
    }

    friend ostream& operator<<(ostream& os, Point& p){
        cout << "("
        << p.x 
        << ","
        << p.y 
        << ")"
        << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Point& p){
        string buffer;
        getline(is, buffer);

        cout << buffer << endl;
        buffer = buffer.substr(1, buffer.size()-2);
        cout << buffer << endl;
        
        stringstream ss(buffer);

        string strX, strY;

        getline(ss, strX, ',');
        getline(ss, strY, ',');

        cout << strX << endl;
        cout << strY << endl;
        stringstream ssX(strX), ssY(strY);

        int x, y;
        ssX >>  x;
        ssY >> y;

        p.x = x;
        p.y = y;
        // p.setX(x);
        // p.setY(y);


        is >> x;
        is >> y;

        return is;
    }
};



int main() {
    Point p;
    p.setX(10);
    p.setY(5);
    p.printPoint();

    cout << p; // operator<<(cout, p);
    // p.operator<<(cout); // p << cout;
    cin >> p;

    cout << p;
    return 0;
}