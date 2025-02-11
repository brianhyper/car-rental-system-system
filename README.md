Vehicle Rental System (Group 5 OOP Project)

Overview

The Vehicle Rental System is a C++ project for a service that lets customers rent vehicles and store owners manage their inventory. It uses Object-Oriented Programming (OOP) to handle tasks like user login, vehicle management, and rental tracking.

Features

1. For Customers

Sign Up: Create an account with a username, password, phone number, and national ID. Each customer gets a unique ID.

Login: Log in to access your account.

View Vehicles: See all available vehicles for rent.

Rent a Vehicle: Pick a vehicle and specify how many days you want to rent it.

View Rental History: Check the vehicles you have rented before.

2. For Store Owners

Login: Use predefined credentials to log in.

View All Vehicles: See details of all vehicles in the system.

Add Vehicles: Add new vehicles to the inventory.

Remove Vehicles: Delete vehicles from the system.

View Rented Vehicles: Check which vehicles are currently rented out.

3. Key Features

Dynamic Memory: Vehicles are stored in memory and cleaned up when the program ends.

Unique IDs: Ensures each customer has a unique national ID during sign-up.

Rental Status: Tracks which vehicles are rented, who rented them, and for how long.

Files in the Project

main.cpp: Handles the main program, menus, and user interactions.

Vehicle.h: Defines the Vehicle class to manage vehicle details and rentals.

Customer.h: Defines the Customer class to manage customer details and rental history.

Classes

Vehicle Class

Attributes:

vehicleID, brand, model, rentalRate, available, renterID, rentalDays, totalCost

Methods:

displayDetails(): Shows vehicle information.

rent(): Marks a vehicle as rented and calculates the cost.

returnVehicle(): Makes the vehicle available again.

Customer Class

Attributes:

username, password, phoneNumber, nationalID, uniqueID, rentalHistory

Methods:

authenticate(): Checks if the username and password are correct.

addRental(): Adds a vehicle to the customer’s rental history.

displayDetails(): Shows customer information and rental history.

How to Run

Compile the program:

g++ main.cpp -o VehicleRentalSystem

Run the program:

./VehicleRentalSystem

Follow the instructions on the screen to log in as a customer or store owner.

Example Workflows

For Customers

Sign up with a username, password, phone number, and national ID.

Log in to your account.

View available vehicles and rent one for a certain number of days.

Check your rental history.

For Store Owners

Log in with the username owner and password adminpass.

Add a new vehicle to the system.

View all vehicles or only rented ones.

Remove vehicles from the system if needed.

Notes

Memory Cleanup: The program removes all stored vehicles from memory when it ends .

Future Upgrades: This system can be improved with features like a database or a graphical interface.

Authors

Group 5 OOP Project Team
