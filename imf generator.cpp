//*******************************************************IMF Generator**********************************************//

// This program generates an Initial Mass Function (IMF) for a stellar population.
// It can generate the IMF based on either the number of stars or the total cluster mass.

#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>

using namespace std;

// Global variables
int N = 100000; // Number of stars
int M = 60000;  // Total cluster mass

// Function prototypes
void imf_num();  // Generate IMF based on the number of stars
void imf_mass(); // Generate IMF based on the total cluster mass
string int_to_str(double); // Convert a double to a string

int main() {
    // Generate IMF using the total cluster mass
    imf_mass(); // Change to imf_num() to generate IMF based on the number of stars
}

// Function to generate IMF based on the number of stars
void imf_num() {
    double *m, x, mass = 0, dm;
    int count = 0;
    string name = "imf N = " + int_to_str(N) + ".dat"; // Output file name
    ofstream write(name.c_str(), ios::out); // Open output file

    m = new double[N]; // Allocate memory for star masses

    // Generate random masses for stars based on the IMF
    for (int i = 0; i < N; i++) {
        x = ((double)rand() / RAND_MAX); // Random number between 0 and 1

        if (x < 0.76)
            m[i] = pow(2.13 - 1.2 * x, -3.3); // Low-mass stars
        else
            m[i] = pow(10.6 - 10.8 * x, -0.77); // High-mass stars
    }

    // Bin the masses and count the number of stars in each bin
    for (mass = 0.08; mass <= 150; mass += dm) {
        dm = mass * 0.1; // Bin width (can be constant or variable)

        for (int i = 0; i < N; i++) {
            if (m[i] <= mass + dm && m[i] >= mass)
                count++; // Count stars in the current bin
        }

        // Write the binned data to the output file
        write << log10(mass + dm) << "            " << log10(count / (dm)) << endl;

        count = 0; // Reset the counter for the next bin
    }
}

// Function to generate IMF based on the total cluster mass
void imf_mass() {
    double *m, x, mass = 0, dm;
    int count = 0, dim = M / 0.08; // Estimate the number of stars based on the cluster mass
    string name = "imf M = " + int_to_str(M) + ".dat"; // Output file name
    ofstream write(name.c_str(), ios::out); // Open output file

    m = new double[dim]; // Allocate memory for star masses

    // Generate random masses for stars until the total mass exceeds the cluster mass
    for (int i = 0; ; i++) {
        x = ((double)rand() / RAND_MAX); // Random number between 0 and 1

        if (x < 0.76)
            m[i] = pow(2.13 - 1.2 * x, -3.3); // Low-mass stars
        else
            m[i] = pow(10.6 - 10.8 * x, -0.77); // High-mass stars

        if (m[i] < 150)
            mass += m[i]; // Add the mass to the total cluster mass

        // Stop when the total mass exceeds the cluster mass
        if (mass > M) {
            N = i; // Update the number of stars
            cout << N; // Print the number of stars
            break;
        }
    }

    // Bin the masses and count the number of stars in each bin
    for (mass = 0.08; mass <= 150; mass += dm) {
        dm = mass * 0.1; // Bin width (can be constant or variable)

        for (int i = 0; i < N; i++) {
            if (m[i] <= mass + dm && m[i] >= mass)
                count++; // Count stars in the current bin
        }

        // Write the binned data to the output file
        write << log10(mass + dm) << "            " << log10(count / (dm)) << endl;

        count = 0; // Reset the counter for the next bin
    }
}

// Function to convert a double to a string
string int_to_str(double u) {
    string name;
    stringstream convert;

    convert << u; // Convert the double to a string
    name = convert.str();

    return name;
}

// Written by Ahmed Farhani Asl