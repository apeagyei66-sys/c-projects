#include <iostream>

int main()
{
    double temp;
    char unit;

    std::cout << "***** Temperature conversion *****\n" << std::endl;
    std::cout << " F = Fahrenheit\n" << std::endl;
    std::cout << "C = Celcius\n" << std::endl;
    std::cout << "What unit would you like to convert to: " << std::endl;
    std::cin >> unit;

    if(unit == 'F' || unit == 'f'){
        std::cout << "Enter the temperature in Celcius: " << std::endl;
        std::cin >> temp;

        temp = (1.8 * temp) + 32.0;
        std::cout << "Temperature is: " << temp << "F\n";
    }
    else if(unit == 'C' || unit == 'c'){
        std::cout << "Enter the temperature in Fahrenheit: " << std::endl;
        std::cin >> temp;

        temp = (temp - 32) / 1.8;
        std::cout << "Temperature is: " << temp << "C\n";
    }
    else{
        std::cout << "Please enter only C or F\n";
    }
    
        std::cout << "***********************************";
    
    return 0;
}