#include <iostream> 

int main()
{
    // arithmetic operators = return the result of a specific 
    //                        arithmetic operation (+ - * /)

    int students = 21; 

    //students = students + 1;
    //students+=1;
    //students++;

    //students = students - 2;
    //students-=2;
    //students--;

    //students = students * 2;
    //students*=2;

    //students = students / 3;
    students/=3;

    int remainder = students % 2;

    std::cout << remainder;

    return 0;
}