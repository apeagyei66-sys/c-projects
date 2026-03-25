#include <iostream>
#include <string>

using namespace std;

int main() {
    string firstName, middleName, lastName, fullName;

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your middle name: ";
    cin >> middleName;

    cout << "Enter your last name: ";
    cin >> lastName;

    // Combine the names with spaces
    fullName = firstName + " " + middleName + " " + lastName;

    cout << "Your full name is: " << fullName << endl;

    return 0;
}