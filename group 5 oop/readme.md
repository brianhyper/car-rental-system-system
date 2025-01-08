   Vehicle Rental System - README

   Overview:
This is a  Vehicle Rental System that allows customers to rent vehicles and store owner to manage their fleet. The system handles customer registration, login, rental history tracking, and vehicle management.

   Features:
-   Customer Features:  
  - Sign up and login.
  - View available vehicles.
  - Rent vehicles and track rental history.
  
-   Store Owner Features:  
  - Login to manage vehicles.
  - Add, remove, and view vehicles.
  - View rented vehicles.

   Prerequisites:
- C++ Compiler (e.g., GCC, Clang).
- C++11 or later support for `std::hash` and `regex`.

   Compilation:
1. Save the project files: `main.cpp`, `Customer.h`, `Vehicle.h`.
2. Compile the code using a C++ compiler:
   ```bash
   g++ main.cpp -o VehicleRentalSystem -std=c++11
   ```

   Running the System:
1. Execute the compiled file:
   ```bash
   ./VehicleRentalSystem
   ```
2. Follow the prompts to log in as a   Customer   or   Store Owner  , or sign up as a   Customer  .

   How to Use:
-   Customer Menu:  
  - View available vehicles.
  - Rent a vehicle by providing the vehicle ID.
  - View rental history.
  
-   Store Owner Menu:  
  - View all vehicles.
  - View rented vehicles.
  - Add or remove vehicles from the system.

   Challenges Faced:
- Password hashing initially used OpenSSL but was later replaced with `std::hash` for simplicity and no external dependencies.
- Validation of phone numbers and national IDs using regular expressions.
- Ensured secure storage of passwords and dynamic management of vehicle data.

   Future Improvements:
- Add persistent data storage (e.g., text files or database).
- Transition to a graphical user interface (GUI).
- Implement stronger password hashing algorithms like bcrypt.

   License:
This project is open-source and available under the MIT License.

---

Feel free to contribute or ask questions about the system!
