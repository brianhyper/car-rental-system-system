#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include <functional>  // For std::hash
#include <sstream>
#include <iomanip>
using namespace std;

// Helper function to hash passwords using std::hash 
size_t hashPassword(const string& password) {
    std::hash<string> hasher;
    return hasher(password);  // Returns the hash as a size_t
}

// Class for managing customer details and rental history
class Customer {
public:
    string username;          // Username of the customer
    size_t hashedPassword;    // Hashed password (using std::hash)
    string phoneNumber;       // Customer's phone number
    string nationalID;        // Customer's national ID
    string uniqueID;          // Unique ID for the customer
    vector<string> rentalHistory;  // History of rented vehicles


    // Static counter to generate unique IDs
    static int uniqueIDCounter;

    // Default constructor
    Customer() : username(""), hashedPassword(0), phoneNumber(""), nationalID(""), uniqueID("") {}

    // Constructor with parameters
    Customer(string user, string pass, string phone, string id)
        : username(user), phoneNumber(phone), nationalID(id) {
        hashedPassword = hashPassword(pass); // Hash the password
        uniqueID = "UID" + to_string(++uniqueIDCounter); // Generate a unique ID
    }

    // Authenticate the customer by comparing hashed passwords
    bool authenticate(const string& user, const string& pass) const {
        return username == user && hashedPassword == hashPassword(pass);
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

