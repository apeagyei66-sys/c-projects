#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int numVectors;
    double totalX = 0.0;
    double totalY = 0.0;
    
    // Pi constant for degree to radian conversion
    const double PI = acos(-1.0);

    cout << "--- Resultant Vector Calculator ---" << endl;
    cout << "Enter the number of vectors you want to add: ";
    cin >> numVectors;

    // Input validation to ensure a positive number of vectors
    if (numVectors <= 0) {
        cout << "Invalid number of vectors. Please restart the program." << endl;
        return 1;
    }

    // Loop to get the magnitude and angle for each vector
    for (int i = 1; i <= numVectors; i++) {
        double magnitude, angleDegrees;

        cout << "\nVector " << i << ":" << endl;
        cout << "Enter magnitude: ";
        cin >> magnitude;
        cout << "Enter angle (in degrees from the positive x-axis): ";
        cin >> angleDegrees;

        // Convert angle from degrees to radians for the cmath functions
        double angleRadians = angleDegrees * (PI / 180.0);

        // Calculate X and Y components and add to the running total
        double compX = magnitude * cos(angleRadians);
        double compY = magnitude * sin(angleRadians);

        totalX += compX;
        totalY += compY;
    }

    // Calculate the resultant magnitude using the Pythagorean theorem
    double resultantMagnitude = sqrt((totalX * totalX) + (totalY * totalY));

    // Calculate the resultant angle in radians using atan2 (handles quadrants automatically)
    double resultantAngleRadians = atan2(totalY, totalX);

    // Convert the resultant angle back to degrees
    double resultantAngleDegrees = resultantAngleRadians * (180.0 / PI);

    // If the angle is negative, convert it to a positive equivalent (0 to 360)
    if (resultantAngleDegrees < 0) {
        resultantAngleDegrees += 360.0;
    }

    // Output the final results
    cout << "\n======================================" << endl;
    cout << "          FINAL RESULTANT             " << endl;
    cout << "======================================" << endl;
    cout << "X Component (Rx): " << totalX << endl;
    cout << "Y Component (Ry): " << totalY << endl;
    cout << "Magnitude (R):    " << resultantMagnitude << endl;
    cout << "Direction:        " << resultantAngleDegrees << " degrees" << endl;
    cout << "======================================" << endl;

    return 0;
}


