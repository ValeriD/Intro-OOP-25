#include <iostream>

using namespace std;

int ERROR = 2147483647;

// typedef unsigned long size_t; //
struct vector_t
{
    int *data;
    size_t size;
    size_t capacity;
} typedef Vector;

Vector *initVector();

/**
 * @brief Adds the number in the back of the vector
 * 
 * @param v 
 * @param number 
 */
void pushBack(Vector *v, int number);

/**
 * @brief Resizes the vector
 * 
 * @param v 
 */
void resize(Vector *v);


/**
 * @brief Prints the vector in the specified format
 * 
 */

// Vector's size:
// Vector's capacity:
// Vector's data:
void print(Vector *v);

/**
 * @brief Returns the element at the provided index
 *
 * @param v
 * @param index
 * @return int
 */
int at(Vector *v, int index);

/**
 * @brief Pops the last element of the vector
 *
 * @param v
 * @return int if successful, ERROR - if not
 */
int pop(Vector *v);

/**
 * @brief Frees the memory allocated by the vector
 *
 * @param v
 */
void destroy(Vector *v);

int main()
{
    struct vector_t *v = initVector();
    cout << v->size << endl;
    v->data[v->size] = 1;

    for (unsigned i = 0; i < v->size; i++)
    {
        cout << v->data[i];
    }

    delete[] v->data; // *(v).data
    delete v;
    return 0;
}

Vector *initVector()
{
    Vector *v = new struct vector_t;
    v->size = 0;
    v->capacity = 2;
    v->data = new int[v->capacity];
    return v;
}