#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

class Point {
    double _x, _y;

public:
    Point() 
    : _x(0), _y(0)
    {}

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
        
        //1.2,2.8
        string numbers = buffer.substr(1, buffer.size()-2); // abcd (0,2) -> ab, abcd (1,2) -> bc, abcd (1,3) -> bcd
        
        stringstream ss(numbers);
        string x, y;

        getline(ss, x, ',');
        getline(ss, y, ',');
        

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

int main(){
    fstream fs;

    string filename = "tmp.txt";
    fs.open(filename, ios::in | ios::out); // read / write
    if(!fs.is_open()){
        cout << "Couldn't open file: " << filename << endl;
        return -1;
    }
    vector<Point> points;

    while(!fs.eof()){
        Point p;
        fs >> p;
        points.push_back(p);
    }
    
    for(Point& p: points){
        cout << p << endl;
    }
    fs.close();

    fs.open("output.txt", ios::out | ios::trunc);
    cout << fs.fail() << endl;
    if(!fs.is_open()) {
        cout << "Failed to open" << endl;
    }
    fs << points[0];

    fs.close();
    return 0;
}