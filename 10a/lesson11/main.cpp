#include<iostream>
#include<fstream>

using namespace std;



int main() {
    ofstream ofs;
    ifstream ifs;
    fstream fs;

    fs.open("tmp.txt", ios::in | ios::out | ios::trunc);

    fs.seekp(0);

    fs << "Hello from file1" << endl;

    // fs.seekg();
    // fs.seekp();

    // fs.tellg();
    // fs.tellp();

    fs.close();
    return 0;
}