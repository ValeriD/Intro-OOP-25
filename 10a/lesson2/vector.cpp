#include <iostream>

using namespace std;

///////////////////////////////
//* snake_case
//* PascalCase
//* camileCase
//* kebab-case
//////////////////////////////

//////////////////////////////
// Diff between i++ and ++i
//////////////////////////////
// int i++(int i)
// {
//     int tmp = i;
//     i = i + 1;
//     return tmp;
// }

// int ++i(int)
// {
//     return i + 1;
// }
//////////////////////////////

int ERROR = 2147483647;

struct vector_t
{
    int *data;
    size_t size;
    size_t capacity;
} typedef Vector;

struct vector_t *initVector();

void pushBack(Vector *v, int number);

void resize(Vector *v);

//////////////////////////////
// Vector's size:
// Vector's capacity:
// Vector's data:
//////////////////////////////
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
 * @return int the element returned
 */
int pop(Vector *v);

/**
 * @brief Frees the memory allocated by the vector
 *
 * @param v
 */
void destroy(Vector *v);

/**
 * @brief Adds an element in the beginning of the vector
 *
 * @param v
 * @param number
 */
void pushFront(Vector *v, int number);

/**
 * @brief Pops the first element of the vector
 *
 * @param v
 * @return int
 */
int popFront(Vector *v);

/**
 * @brief Inserts an element at a given index
 *
 * @param v
 * @param index
 * @param number
 * @return int
 */
int insert(Vector *v, int index, int number);

/**
 * @brief Removes an element at a given index
 *
 * @param v
 * @param index
 * @param number
 * @return int
 */
int remove(Vector *v, int index, int number);

int main()
{
    Vector *v = initVector();
    // pushBack(v, 2);
    // pushBack(v, 3);
    print(v);
    return 0;
}

struct vector_t *initVector()
{
    Vector *v = new Vector();
    v->size = 0;
    v->capacity = 2; // 5
    v->data = new int[v->capacity];

    return v;
}

void pushBack(Vector *v, int number)
{
    if (v->size == v->capacity)
    {
        resize(v);
    }
    v->data[v->size++] = number; //++i i++
}

void resize(Vector *v)
{
    v->capacity *= 2;
    int *tmp = new int[v->capacity];
    for (size_t i = 0; i < v->size; i++)
    {
        tmp[i] = v->data[i];
    }
    delete[] v->data;
    v->data = tmp;
}

void print(Vector *v)
{
    cout << "Vector's size: " << v->size << endl;
    cout << "Vector's size: " << v->capacity << endl;
    cout << "Vector's data: [";

    if (v->size > 0)
        cout << v->data[0];
    for (size_t i = 1; i < v->size; i++)
    {
        cout << " " << v->data[i];
    }
    cout << "]" << endl;
}

//////////////////////////////
