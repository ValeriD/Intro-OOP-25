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
    String();

    /**
     * @brief Construct a new String object with the provided value
     *
     * @param str
     */
    String(const char *str);

    /**
     * @brief Destroy the String object
     *
     */
    ~String();

    /**
     * @brief Returns the string as a C-style string - char*
     *
     * @return const char*
     */
    char *toCString() const;

    /**
     * @brief Returns the length of the string
     *
     * @return size_t
     */
    size_t length() const;

    /**
     * @brief Appends a character to the string
     *
     * @param ch
     */
    void append(char ch);

    /**
     * @brief Append the provided string to the current string
     *
     * @param str
     */
    void concat(const char *str);

    /**
     * @brief Compares 2 strings
     *
     * @param other
     * @return int 0 if the strings are equal, 1 if the current string is greater, -1 if the current string is smaller
     */
    int compare(const String &other) const;
};