#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Class for managing customer details and rental history
class Customer {
public:
    string username;          
    string password;          
    string phoneNumber;        
    string nationalID;        
    string uniqueID;          
    vector<string> rentalHistory; 

    // Static counter to generate unique IDs
    static int uniqueIDCounter;

    // Default constructor
    Customer() : username(""), password(""), phoneNumber(""), nationalID(""), uniqueID("") {}

    // Constructor with parameters
    Customer(string user, string pass, string phone, string id)
        : username(user), password(pass), phoneNumber(phone), nationalID(id) {
        uniqueID = "UID" + to_string(++uniqueIDCounter); // Generate a unique ID
    }

    // Authenticate the customer
    bool authenticate(const string& user, const string& pass) const {
        return username == user && password == pass;
    }

    // Add a rental to the history
    void addRental(const string& vehicleID) {
        rentalHistory.push_back(vehicleID);
    }

    // Display customer details and rental history
    void displayDetails() const {
        cout << "Username: " << username << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "National ID: " << nationalID << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Rental History: ";
        for (const string& rental : rentalHistory) {
            cout << rental << " ";
        }
        cout << endl;
    }
};

// Initialize static unique ID counter
int Customer::uniqueIDCounter = 0;

#endif

