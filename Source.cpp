/* CIS 1202.201 Daniel Blair 7/28/2024
 * This program defines a function 'character' that calculates a character based on
 * a given starting character and an offset, with error handling for invalid inputs.
 * It includes custom exceptions 'invalidCharacterException' and 'invalidRangeException'
 * to handle non-letter start characters and out-of-range results, respectively.
 * The main function tests the 'character' function with various inputs and demonstrates
 * exception handling.
 */
#include <iostream>
#include <stdexcept>
using namespace std;
// Custom exception class for invalid start character
class invalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character: start must be a letter (A-Z, a-z)";
    }
};
// Custom exception class for invalid resulting character
class invalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid range: resulting character is not a letter (A-Z, a-z)";
    }
};
char character(char start, int offset) {
    // Check if start is a letter
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {
        throw invalidCharacterException();
    }
    // Calculate the character with the given offset
    char result = start + offset;
    // Check if the result is a letter
    if (!((result >= 'A' && result <= 'Z') || (result >= 'a' && result <= 'z'))) {
        throw invalidRangeException();
    }
    // Return the resulting character
    return result;
}
int main() {
    // Test cases
    char testStarts[] = { 'a', 'Z', 'm', 'A', '*', 'z' };
    int testOffsets[] = { 1, -1, 13, 25, 10, 1 };
    int numTests = sizeof(testStarts) / sizeof(testStarts[0]);
    for (int i = 0; i < numTests; ++i) {
        try {
            char result = character(testStarts[i], testOffsets[i]);
            cout << "character('" << testStarts[i] << "', " << testOffsets[i] << ") = " << result << endl;
        }
        catch (const invalidCharacterException& e) {
            cerr << "Error for character('" << testStarts[i] << "', " << testOffsets[i] << "): " << e.what() << endl;
        }
        catch (const invalidRangeException& e) {
            cerr << "Error for character('" << testStarts[i] << "', " << testOffsets[i] << "): " << e.what() << endl;
        }
    }
    return 0;
}