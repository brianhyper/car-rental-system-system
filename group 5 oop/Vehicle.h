#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

// Base class Vehicle
class Vehicle {
public:
    string vehicleID;   // Unique ID for the vehicle
    string brand;       // Vehicle brand (e.g., Toyota)
    string model;       // Vehicle model (e.g., Corolla)
    double rentalRate;  // Daily rental rate
    bool available;     // Availability status of the vehicle
    string renterID;    // ID of the customer renting the vehicle
    int rentalDays;     // Number of days the vehicle is rented
    double totalCost;   // Total rental cost

    // Constructor
    Vehicle(string id, string b, string m, double rate)
        : vehicleID(id), brand(b), model(m), rentalRate(rate), available(true),
          renterID(""), rentalDays(0), totalCost(0.0) {}

    // Display vehicle details
    virtual void displayDetails() {
        cout << "ID: " << vehicleID 
             << ", Brand: " << brand 
             << ", Model: " << model 
             << ", Rate: $" << rentalRate 
             << "/day, Available: " << (available ? "Yes" : "No") 
             << endl;
    }

    // Rent the vehicle
    void rent(const string& customerID, int days) {
        if (available) {
            available = false;          // Mark the vehicle as rented
            renterID = customerID;      // Assign the renter's ID
            rentalDays = days;          // Set the number of rental days
            totalCost = rentalRate * days; // Calculate total cost
            cout << "Vehicle rented successfully for " 
                 << days << " day(s). Total cost: $" << totalCost << endl;
        } else {
            cout << "Vehicle is not available!" << endl;
        }
    }

    // Return the vehicle
    void returnVehicle() {
        available = true;    // Mark the vehicle as available
        renterID = "";       // Clear the renter's ID
        rentalDays = 0;      // Reset rental days
        totalCost = 0.0;     // Reset total cost
        cout << "Vehicle returned successfully!" << endl;
    }
};

#endif
