#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    bool isPalindrome = true;

    cout << "Enter a word: ";
    cin >> word;

    int length = word.length();

    // Loop through the first half of the word and compare with the second half
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - 1 - i]) {
            isPalindrome = false;
            break; // Stop checking if a mismatch is found
        }
    }

    if (isPalindrome) {
        cout << word << " is a palindrome." << endl;
    } else {
        cout << word << " is not a palindrome." << endl;
    }

    return 0;
}