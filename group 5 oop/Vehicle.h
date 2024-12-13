#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

// Base class Vehicle
class Vehicle {
public:
    string vehicleID;  
    string brand;       
    string model;       
    double rentalRate;  
    bool available;     
    string renterID;    
    int rentalDays;     
    double totalCost; 

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
            available = false;         
            renterID = customerID;      
            rentalDays = days;          
            totalCost = rentalRate * days; // Calculate total cost
            cout << "Vehicle rented successfully for " 
                 << days << " day(s). Total cost: $" << totalCost << endl;
        } else {
            cout << "Vehicle is not available!" << endl;
        }
    }

    // Return the vehicle if a customer rents one
    void returnVehicle() {
        available = true;    
        renterID = "";      
        rentalDays = 0;     
        totalCost = 0.0;    
        cout << "Vehicle returned successfully!" << endl;
    }
};

#endif
