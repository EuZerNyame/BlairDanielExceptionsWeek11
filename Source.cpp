#include <iostream>
#include <stdexcept>

using namespace std;

// Custom exception class
class invalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character: start must be a letter (A-Z, a-z)";
    }
};

char character(char start, int offset) {
    // Check if start is a letter
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {
        throw invalidCharacterException();
    }

    // Calculate the character with the given offset
    char result = start + offset;

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

    return 0;
}
