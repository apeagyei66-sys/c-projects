#include <iostream>

int main()
{
   char grade;
   
   std::cout << "What letter grade?: " << std::endl;
   std::cin >> grade;

    switch (grade){
    case 'A':
        std::cout << "You did great!" << std::endl;
        break;
    case 'B':
        std::cout << "You did good!" << std::endl;
        break;
    case 'C':
        std::cout << "You did okay!" << std::endl;
        break;
    case 'D':
        std::cout << "You did not do good!" << std::endl;
        break;
    case 'F':
        std::cout << "YOU FAILED!" << std::endl;
        break;
        default:
        std::cout << "Please only enter in a letter grade (A-F)" << std::endl;
    }
    


    return 0;
}