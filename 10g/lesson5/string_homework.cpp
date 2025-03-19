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
     * @brief Construct a new String object by copying another string
     *
     * @param other
     */
    String(const String &other);

    /**
     * @brief Copies the values from the other string in this string
     *
     * @param other
     * @return String&
     */
    String &operator=(const String &other);

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
};