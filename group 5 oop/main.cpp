#include "Vehicle.h"
#include "Customer.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <regex>  
using namespace std;

// Validate phone number (exactly 10 digits, and all digits)
bool validatePhoneNumber(const string& phone) {
    return regex_match(phone, regex("^[0-9]{10}$"));
}

// Validate national ID (exactly 8 digits, and all digits)
bool validateNationalID(const string& id) {
    return regex_match(id, regex("^[0-9]{8}$"));
}

unordered_map<string, Customer> customersByNationalID;

void customerMenu(vector<Vehicle*>& vehicles, Customer& customer);
void ownerMenu(vector<Vehicle*>& vehicles);

int main() {
    unordered_map<string, string> owners = { {"owner", "adminpass"} };

    vector<Vehicle*> vehicles;
    vehicles.push_back(new Vehicle("C001", "Toyota", "Corolla", 5000.0));
    vehicles.push_back(new Vehicle("B001", "Mazda", "CX-5", 7000.0));

    int choice;
    while (true) {
        cout << "Welcome to the Vehicle Group 5 Rental System!" << endl;
        cout << "1. Login as Customer\n2. Sign up as Customer\n3. Login as Store Owner\n4. Exit\n";
        cin >> choice;

        if (choice == 1) {
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
            string username, password, phone, nationalID;
            cout << "Choose a Username: ";
            cin >> username;
            cout << "Choose a Password: ";
            cin >> password;
            cout << "Enter your Phone Number: ";
            cin >> phone;

            // Validate phone number
            if (!validatePhoneNumber(phone)) {
                cout << "Invalid phone number. It must be exactly 10 digits." << endl;
                continue;  // Skip the rest of the sign-up process
            }

            cout << "Enter your National ID Number: ";
            cin >> nationalID;

            // Validate national ID
            if (!validateNationalID(nationalID)) {
                cout << "Invalid national ID. It must be exactly 8 digits." << endl;
                continue;  // Skip the rest of the sign-up process
            }

            try {
                Customer newCustomer(username, password, phone, nationalID);
                customersByNationalID[nationalID] = newCustomer;
                cout << "Account created successfully! Your unique ID is: " << newCustomer.uniqueID << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        } else if (choice == 3) {
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
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid option, please try again!" << endl;
        }
    }

    // Clean up dynamic memory
    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}

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
            string id;
            cout << "Enter Vehicle ID to remove: ";
            cin >> id;

            auto it = find_if(vehicles.begin(), vehicles.end(), [&id](Vehicle* v) { return v->vehicleID == id; });

            if (it != vehicles.end()) {
                delete *it;
                vehicles.erase(it);
                cout << "Vehicle removed successfully!" << endl;
            } else {
                cout << "Vehicle not found!" << endl;
            }
        }
    } while (choice != 5);
}
