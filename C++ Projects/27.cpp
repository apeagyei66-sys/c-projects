#include <iostream>
#include <ctime>

int main() {
    srand(time(NULL));
    int num = (rand() % 100) + 1;
    int guess;
    int tries = 0;

    std::cout << "** NUMBER GUESSING GAME **\n";

    do {
        std::cout << "Enter a guess (1-100): ";
        std::cin >> guess;
        tries++;

        if (guess > num) {
            std::cout << "Too high!\n";
        } else if (guess < num) {
            std::cout << "Too low!\n";
        } else {
            std::cout << "CORRECT! # of tries: " << tries << "\n";
        }

    } while (guess != num); // The loop only continues if the guess is WRONG

    std::cout << "**********\n";

    return 0;
}