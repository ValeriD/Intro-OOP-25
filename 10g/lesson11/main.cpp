#include<iostream>
#include<sstream>

using namespace std;

class Point {
    double _x, _y;

public:
    Point(double x, double y)
    : _x(x), _y(y) 
    {}

    void print() const {
        cout << "(" << _x << "," << _y << ")" << endl;
    }

    double getX() const {
        return this->_x;
    }

    double getY() const {
        return this->_y;
    }

    friend ostream& operator<<(ostream& os, const Point& p){
        os << "(" << p._x << "," << p._y << ")";
    
        return os;
    }

    friend istream& operator>>(istream& is, Point& p){
        // (1.2,2.8)

        string buffer;
        getline(is, buffer); // abcd\n -> abcd, abcd \n-> "abcd "
        cout << buffer << endl;
        
        //1.2,2.8
        string numbers = buffer.substr(1, buffer.size()-2); // abcd (0,2) -> ab, abcd (1,2) -> bc, abcd (1,3) -> bcd
        cout << numbers << endl;
        
        stringstream ss(numbers);
        string x, y;

        getline(ss, x, ',');
        getline(ss, y, ',');
        
        cout << x << " " << y << endl;

        p._x = p.getDoubleFromString(x);
        p._y = p.getDoubleFromString(y);
        
        return is;
    }

    double getDoubleFromString(string& str) const {
        // return stod(str);
        stringstream ss(str);
        double res;
        ss >> res;
        return res;
    }
};

// ostream& operator<<(ostream& os, Point& p){
//     os << "(" << p.getX() << "," << p.getY() << ")";

//     return os;
// }

int main(int argc, char** argv) { // 2 ["arg1", "arg2"]

    // cout << argc << endl;
    // cout << argv[0] << endl;
    // cout << argv[1] << endl;
    // int a;
    // cin >> a;
    // cout << a;

    Point p(1.0,2.5);
    Point p2(2, 2);

    // (x,y)
    // p.print();
    
    cout << p << endl; // operator<<(cout, p);

    // cout << "P1: " << p << " P2: " << p2 << endl; // operator<<(operator<<(operator<<(operator<<(cout, "P1: "), p), "P2: "), p2)
    // p.operator<<(cout);
    // p << cout;
    // cout << p << endl;

    cin >> p; // x y
    cout << p;
    // (1,2)
    // (1,2,3)
    // (1,2,3,4)
    return 0;
}