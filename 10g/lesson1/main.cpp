#include <iostream>
#include <cstring>

using namespace std;

// Causes compilation error
// int test()
// {
//     return test1() + 1;
// }

// int test1()
// {
//     return 1;
// }
typedef char Class;

struct student_t
{
    unsigned int id;
    char *name;
    Class classId;
} typedef Student;

int test();

int test1();

int main()
{
    cout << "Hello world!" << endl;

    int a, b, c;
    char d;
    cin >> a >> b >> c >> d;

    cout << a << endl;

    int *arr = new int[10]; // malloc()

    delete[] arr; // free()

    struct student_t student;
    student.id = 1;
    // strcpy(student.name, "Georgi"); // ERROR no allocated memory
    //RAII
    student.name = strdup("Georgi");
    student.classId = 'A';

    delete[] student.name;

    int arr[16];
    
    return 0;
}

int test()
{
    return test1() + 1;
}

int test1()
{
    return 1;
}