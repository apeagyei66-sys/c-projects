#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate stopping distance
double calculateStoppingDistance(double velocity_mps, double coefficient_friction) {
    const double gravity = 9.81; // Acceleration due to gravity in m/s^2
    // Formula: s = v^2 / (2 * mu * g)
    return pow(velocity_mps, 2) / (2 * coefficient_friction * gravity);
}

// Function to calculate required braking force
double calculateBrakingForce(double mass, double coefficient_friction) {
    const double gravity = 9.81;
    // Formula: F = mu * m * g
    return coefficient_friction * mass * gravity;
}

int main() {
    // Variables for user input
    double mass_kg;
    double velocity_kmh;
    double velocity_mps;
    int road_condition;
    double coefficient_friction;

    cout << "=========================================================\n";
    cout << "       VEHICLE BRAKING DYNAMICS & SAFETY CALCULATOR      \n";
    cout << "=========================================================\n\n";

    // 1. Get Vehicle Data
    cout << "Enter the mass of the vehicle (in kg, e.g., 1600 for a sports car): ";
    cin >> mass_kg;

    cout << "Enter the vehicle's initial speed (in km/h): ";
    cin >> velocity_kmh;

    // Convert km/h to m/s for physics calculations
    velocity_mps = velocity_kmh * (1000.0 / 3600.0);

    // 2. Get Road Conditions using a simple menu
    cout << "\nSelect the road surface condition:\n";
    cout << "1. Dry Asphalt (High Grip)\n";
    cout << "2. Wet Asphalt (Medium Grip)\n";
    cout << "3. Icy/Snowy Road (Low Grip)\n";
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> road_condition;

    // 3. Control Structure to set the friction coefficient
    if (road_condition == 1) {
        coefficient_friction = 0.85; // Typical value for dry roads
        cout << "\nCondition selected: Dry Asphalt.\n";
    } else if (road_condition == 2) {
        coefficient_friction = 0.50; // Typical value for wet roads
        cout << "\nCondition selected: Wet Asphalt.\n";
    } else if (road_condition == 3) {
        coefficient_friction = 0.15; // Typical value for ice
        cout << "\nCondition selected: Icy Road.\n";
    } else {
        cout << "\nInvalid selection. Defaulting to Dry Asphalt (1).\n";
        coefficient_friction = 0.85;
    }

    // 4. Perform Calculations by calling our functions
    double stopping_distance = calculateStoppingDistance(velocity_mps, coefficient_friction);
    double braking_force = calculateBrakingForce(mass_kg, coefficient_friction);
    
    // Calculate deceleration (a = F/m)
    double deceleration = braking_force / mass_kg;

    // 5. Display the Results
    cout << "\n=========================================================\n";
    cout << "                    ANALYSIS RESULTS                     \n";
    cout << "=========================================================\n";
    
    // Set output to show 2 decimal places
    cout << fixed << setprecision(2);
    
    cout << "Initial Speed:       " << velocity_mps << " m/s (" << velocity_kmh << " km/h)\n";
    cout << "Vehicle Mass:        " << mass_kg << " kg\n";
    cout << "Friction Coeff:      " << coefficient_friction << "\n";
    cout << "---------------------------------------------------------\n";
    cout << "Deceleration:        " << deceleration << " m/s^2\n";
    cout << "Total Braking Force: " << braking_force << " Newtons (N)\n";
    cout << "STOPPING DISTANCE:   " << stopping_distance << " meters\n";
    cout << "=========================================================\n";

    return 0;
}


