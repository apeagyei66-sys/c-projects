#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * VEHICLE BRAKING ENGINE - UMaT MECHANICAL ENGINEERING
 * This program receives data from the Python Frontend, 
 * calculates physics, and returns the result.
 */

int main(int argc, char* argv[]) {
    // Check if Python sent all 3 arguments: Mass, Velocity, Friction
    if (argc < 4) {
        return 1; 
    }

    // Convert string arguments from Python into doubles
    double mass = atof(argv[1]);
    double velocity_kmh = atof(argv[2]);
    double mu = atof(argv[3]);
    const double g = 9.81; // Gravity

    // 1. Convert km/h to m/s
    double v_ms = velocity_kmh * (1000.0 / 3600.0);

    // 2. Calculate Stopping Distance: s = v^2 / (2 * mu * g)
    double stopping_distance = pow(v_ms, 2) / (2 * mu * g);

    // 3. Calculate Braking Force: F = mu * m * g
    double braking_force = mu * mass * g;

    // Output formatted with a comma so Python can split it: "Distance,Force"
    cout << fixed << setprecision(2);
    cout << stopping_distance << "," << braking_force;

    return 0;
}