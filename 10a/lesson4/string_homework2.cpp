#include <iostream>

using namespace std;

class String
{
    char *data;
    size_t size;

public:
    /**
     * @brief Construct a new String object and it should have a default value of ""
     *
     */
    String()
    {
        size = 0;
        data = new char[1];
        data[0] = '\0';
    }

    /**
     * @brief Construct a new String object with the provided value
     *
     * @param str
     */
    String(const char *str)
    {
        size = 0;
        while (str[size] != '\0')
        {
            size++;
        }

        data = new char[size + 1];
        for (size_t i = 0; i <= size; i++)
        {
            data[i] = str[i];
        }
    }

    /**
     * TODO: Implement the copy constructor
     * @brief Construct a new String object by copying another string
     *
     * @param other
     */
    String(const String &other);

    /**
     * TODO: Implement the assignment operator
     * @brief Copies the values from the other string in this string
     *
     * @param other
     * @return String&
     */
    String &operator=(const String &other);

    /**
     * TODO: Implement the insert method
     * @brief Inserts a character at the provided index, if the index is bigger than the size of the string, just return the string, withouth modifying it
     *
     * @param index
     * @param c
     * @return String&
     */
    String &insert(size_t index, char c);

    /**
     * TODO: Implement the replace method
     * @brief Replaces the character at the provided index, if the index is bigger than the size of the string, just return the string, withouth modifying it
     *
     * @param index
     * @param c
     * @return String&
     */
    String &replace(size_t index, char c);

    /**
     * TODO: Implement the findFirstOf method
     * @brief Finds the first index, where the provided character is found, return -1 if the character is not found
     *
     * @param c
     * @return int
     */
    int findFirstOf(char c) const;

    /**
     * @brief Destroy the String object
     *
     */
    ~String()
    {
        delete[] data;
    }

    /**
     * @brief Returns the string as a C-style string - char*
     *
     * @return const char*
     */
    char *toCString() const
    {
        return data;
    }

    /**
     * @brief Returns the length of the string
     *
     * @return size_t
     */
    size_t length() const
    {
        return size;
    }

    /**
     * @brief Appends a character to the string
     *
     * @param ch
     */
    void append(char ch)
    {
        char *newData = new char[size + 2];

        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        newData[size] = ch;
        newData[size + 1] = '\0';

        delete[] data;
        data = newData;
        size++;
    }

    /**
     * @brief Append the provided string to the current string
     *
     * @param str
     */
    void concat(const char *str)
    {
        size_t strLen = 0;
        while (str[strLen] != '\0')
        {
            strLen++;
        }

        char *newData = new char[size + strLen + 1];

        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        for (size_t i = 0; i <= strLen; i++)
        {
            newData[size + i] = str[i];
        }

        delete[] data;
        data = newData;
        size += strLen;
    }

    /**
     * @brief Compares 2 strings
     *
     * @param other
     * @return int 0 if the strings are equal, 1 if the current string is greater, -1 if the current string is smaller
     */
    int compare(const String &other) const
    {
        size_t minLen = size < other.size ? size : other.size;

        for (size_t i = 0; i < minLen; i++)
        {
            if (data[i] < other.data[i])
                return -1;
            if (data[i] > other.data[i])
                return 1;
        }

        if (size < other.size)
            return -1;
        if (size > other.size)
            return 1;
        return 0;
    }
};