#include<iostream>
#include<fstream>

using namespace std;


int main(){

    // istream is;
    // ostream os;
    // iostream ios;

    ifstream ifs;
    ofstream ofs;
    fstream fs;

    string filename = "tmp.txt";
    fs.open(filename, ios::in | ios::out | ios::trunc); // read / write
    if(!fs.is_open()){
        cout << "Couldn't open file: " << filename << endl;
        return -1;
    }
    fs.seekp(ios::beg);
    fs << "Hello1 from file" << endl;
    cout << fs.tellp() << endl;
    fs.close();

    // fs.open(filename, ios::in | ios::out | ios::app);
    // if(!fs.is_open()){
    //     cout << "Couldn't open file: " << filename << endl;
    //     return -1;
    // }

    // string buffer;
    // cout << fs.tellg() << endl; // Tell get
    // cout << fs.tellp() << endl; // Tell put
    
    // fs >> buffer;
    // cout << buffer << endl;
    
    // cout << fs.tellg() << endl; // Tell get
    // cout << fs.tellp() << endl; // Tell put
    
    // //Move the cursor back to the start of the line
    // fs.seekg(ios::beg); // 0
    // cout << "Tell get: " << fs.tellg() << endl;
    // cout << "Tell put: " << fs.tellp() << endl;
    
    // getline(fs, buffer);
    // cout << buffer << endl;
    
    // cout << fs.tellg() << endl; // Tell get
    // cout << fs.tellp() << endl; // Tell put
    // fs.close();

    return 0;
}