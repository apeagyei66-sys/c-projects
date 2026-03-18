#include <iostream>

int main()
{
    //ternary operator ?: =nreplacement to an if/else statement 
    // condition ? expressional1 : expressionsl2;

    //int grade = 50;
    //grade >= 60 ? std::cout << "You pass!" << std::endl : std::cout << "You fail!" << std::endl;

    //int number = 9;
    //number % 2 ? std::cout << "ODD" << std::endl : std::cout << "EVEN" << std::endl;

    bool hungry = false;

    //hungry ? std::cout << "You are hungry" << std::endl : std::cout << "You are full" << std::endl;
    std::cout << (hungry ? "You are hungry" : "You are full");

    return 0;
}