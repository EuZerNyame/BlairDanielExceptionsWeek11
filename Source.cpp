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

    // Returning the result character
    return result;
}
int main() {
    try {
        char start = 'a';
        int offset = 1;
        char result = character(start, offset);
        cout << "Resulting character: " << result << endl;
    }
    catch (const invalidCharacterException& e) {
        cerr << e.what() << endl;
    }
    catch (const invalidRangeException& e) {
        cerr << e.what() << endl;
    }
    return 0;
}