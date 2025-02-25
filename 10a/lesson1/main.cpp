#include <iostream>

using namespace std;

struct Student{
    int id;
    char name[20];
} typedef Student;


int main(){
    struct Student s;
    int a = 1;
    cout << a << endl;
    cin >> a;
    char c;
    cin >> c;
    float f;
    double d;
    bool t = true;
    bool f = false;

    char string[20];
    char* str = new char[20];

    delete []str;

    return 0;
}