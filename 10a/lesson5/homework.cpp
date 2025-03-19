#include <iostream>
#include <exception>
using namespace std;

class Vector
{
    int *data;
    size_t size;
    size_t capacity;
    const int id;

    void resize();

public:
    Vector(int id, int capacity);

    ~Vector();

    size_t getSize() const;

    size_t getCapacity() const;

    int getId() const;

    void pushBack(int number);

    int at(int index) const;

    int insert(int index, int value);

    int remove(int index);

    int pop();
};