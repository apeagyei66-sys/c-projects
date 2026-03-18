#include <iostream>

int main() {

    //integer (whole number)
    int age  = 21;
    int year = 2023;
    int days = 7;

    //double (number including decimal)
    double price = 10.99;
    double gpa = 2.5;
    double temperature = 25.1;

    // single character 
    char grade = 'A';
    char initial = 'B';
    char dollarSign =  '$';

    // boolean (true or false)
    bool student = false;
    bool power = true;
    bool forSale = true;

    // string (objects that represents a sequence of text)
    std::string name = "Bro";
    std::string day = "Friday";
    std::string food = "pizza";
    std::string address = "123 Fake St.";

    std::cout << "Hello " <<name << '\n';
    std::cout << "You are " << age << "years old";

    return 0;
}