#include <iostream>
#include <string>

int main()
{
    std::string s = "abcCde";
    size_t startIndex = 2;       // Index of the first character to remove
    size_t numCharsToRemove = 2; // Number of characters to remove

    // Check if the start index is within the bounds of the string
    if (startIndex < s.length())
    {
        s.erase(startIndex, numCharsToRemove);
    }

    std::cout << s << std::endl; // Output: abde

    return 0;
}
