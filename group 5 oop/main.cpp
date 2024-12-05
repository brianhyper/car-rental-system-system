#include "Vehicle.h"
#include "Customer.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Define the map declared as extern in Customer.h
unordered_map<string, Customer> customersByNationalID;

void customerMenu(vector<Vehicle*>& vehicles, Customer& customer);
void ownerMenu(vector<Vehicle*>& vehicles);

int main() {
    // Store Owner login (for demonstration, we hardcode credentials)
    unordered_map<string, string> owners = {{"owner1", "adminpass"}};

    // Sample vehicles
    vector<Vehicle*> vehicles;
    vehicles.push_back(new Vehicle("C001", "Toyota", "Corolla", 50.0));
    vehicles.push_back(new Vehicle("B001", "Yamaha", "MT-07", 30.0));

    int choice;
    while (true) {
        cout << "Welcome to the Vehicle Rental System!" << endl;
        cout << "1. Login as Customer\n2. Sign up as Customer\n3. Login as Store Owner\n4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            // Customer Login
            string username, password;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            bool found = false;
            for (const auto& [id, customer] : customersByNationalID) {
                if (customer.username == username && customer.authenticate(username, password)) {
                    customerMenu(vehicles, customersByNationalID[id]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Invalid credentials!" << endl;
            }
        } else if (choice == 2) {
            // Customer Sign Up
            string username, password, phone, nationalID;
            cout << "Choose a Username: ";
            cin >> username;
            cout << "Choose a Password: ";
            cin >> password;
            cout << "Enter your Phone Number: ";
            cin >> phone;
            cout << "Enter your National ID Number: ";
            cin >> nationalID;

            // Check if National ID already exists
            if (customersByNationalID.find(nationalID) != customersByNationalID.end()) {
                cout << "This National ID is already in the system. Please try again." << endl;
                continue;
            }

            // Create a new customer and store them in the map
            Customer newCustomer(username, password, phone, nationalID);
            customersByNationalID[nationalID] = newCustomer;
            cout << "Account created successfully! Your unique ID is: " << newCustomer.uniqueID << endl;

            // Ask if user wants to create another account or exit
            char continueOption;
            cout << "Do you want to create another account? (y/n): ";
            cin >> continueOption;
            if (continueOption == 'n' || continueOption == 'N') {
                continue;  // Continue with main menu
            }
        } else if (choice == 3) {
            // Store Owner Login
            string username, password;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            if (owners.find(username) != owners.end() && owners[username] == password) {
                ownerMenu(vehicles);
            } else {
                cout << "Invalid credentials!" << endl;
            }
        } else if (choice == 4) {
            // Exit the program
            cout << "Exiting the system. Goodbye!" << endl;
            break; // Exit the while loop and terminate the program
        } else {
            cout << "Invalid option, please try again!" << endl;
        }
    }

    // Cleanup: Delete dynamically allocated vehicles
    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}

// Customer Menu (View vehicles, Rent vehicles)
void customerMenu(vector<Vehicle*>& vehicles, Customer& customer) {
    int choice;
    do {
        cout << "\nCustomer Menu:\n";
        cout << "1. View Available Vehicles\n";
        cout << "2. Rent a Vehicle\n";
        cout << "3. View Rental History\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (auto vehicle : vehicles) {
                if (vehicle->available) vehicle->displayDetails();
            }
        } else if (choice == 2) {
            string id;
            cout << "Enter Vehicle ID to rent: ";
            cin >> id;
            for (auto vehicle : vehicles) {
                if (vehicle->vehicleID == id && vehicle->available) {
                    int days;
                    cout << "Enter the number of days you would like to rent this vehicle: ";
                    cin >> days;
                    vehicle->rent(customer.uniqueID, days);
                    customer.addRental(id);
                    break;
                }
            }
        } else if (choice == 3) {
            customer.displayDetails();
        }
    } while (choice != 4);
}

// Store Owner Menu (Add or Remove vehicles, View rented vehicles)
void ownerMenu(vector<Vehicle*>& vehicles) {
    int choice;
    do {
        cout << "\nStore Owner Menu:\n";
        cout << "1. View All Vehicles\n";
        cout << "2. View Rented Vehicles\n";
        cout << "3. Add Vehicle\n";
        cout << "4. Remove Vehicle\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (auto vehicle : vehicles) {
                vehicle->displayDetails();
            }
        } else if (choice == 2) {
            cout << "\nRented Vehicles:\n";
            for (auto vehicle : vehicles) {
                if (!vehicle->available) {
                    vehicle->displayDetails();
                }
            }
        } else if (choice == 3) {
            // Add Vehicle
            string id, brand, model;
            double rate;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter Brand: ";
            cin >> brand;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Rental Rate: ";
            cin >> rate;

            vehicles.push_back(new Vehicle(id, brand, model, rate));
            cout << "Vehicle added successfully!" << endl;
        } else if (choice == 4) {
            // Remove Vehicle
            string id;
            cout << "Enter Vehicle ID to remove: ";
            cin >> id;

            auto it = find_if(vehicles.begin(), vehicles.end(), [&id](Vehicle* v) { return v->vehicleID == id; });

            if (it != vehicles.end()) {
                delete *it;  // Delete the vehicle from memory
                vehicles.erase(it);  // Remove the vehicle from the list
                cout << "Vehicle removed successfully!" << endl;
            } else {
                cout << "Vehicle not found!" << endl;
            }
        }
    } while (choice != 5);
}