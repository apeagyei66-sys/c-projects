#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;

    cout << "Enter a word: ";
    cin >> word;

    cout << "The length of the word is: " << word.length() << " characters." << endl;

    return 0;
}