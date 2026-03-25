#include <iostream>
#include <string>

using namespace std;

int main() {
    string mainText, subString;

    cout << "Enter the main word or text: ";
    cin >> mainText;

    cout << "Enter the substring to look for: ";
    cin >> subString;

    // find() returns the starting index of the substring
    int index = mainText.find(subString);

    if (index != string::npos) {
        cout << "The substring was found at index: " << index << endl;
    } else {
        cout << "The substring was not found." << endl;
    }

    return 0;
}