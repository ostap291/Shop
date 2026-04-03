🛒 Shop — Self-Checkout System (C++)

A simple object-oriented simulation of a self-checkout system for different types of stores.
This project demonstrates polymorphism, inheritance, and clean separation of responsibilities in C++.

🚀 Features
🧾 Scan products into a cart
🏬 Support for multiple store types:
Grocery store
Tech store
🎟️ Promo code system
💸 Store-specific discount logic
📄 Automatic receipt generation (saved to .txt files)
🔄 Cart reset after checkout
🧠 Architecture

The project follows OOP principles:

🔹 Store (Abstract Base Class)

Defines common functionality:

Store name
Promo code handling
Virtual methods:
calculateStoreDiscount
generateReceipt
🔹 GroceryStore (Derived)
Promo: FOOD20 → 20% discount
Extra discount: 5% if total > 500 грн
Receipt format: simple grocery style
🔹 TechStore (Derived)
Promo: TECH10 → 10% discount
Extra discount: 1000 грн if total > 10000 грн
Receipt format: tech store style with warranty info
🔹 SelfCheckout

Handles:

Product scanning
Total calculation
Applying discounts
Receipt generation
Cart management
📦 Example Usage
SelfCheckout terminal;

Store* grocery = new GroceryStore();
Store* tech = new TechStore();

terminal.scanProduct("Bread", 30.0);
terminal.scanProduct("Milk", 45.0);
terminal.scanProduct("Coffee", 450.0);

// Apply valid promo
terminal.payAndCheckout(grocery, "FOOD20");

terminal.scanProduct("Laptop", 25000.0);
terminal.scanProduct("Mouse", 1200.0);

// Invalid promo
terminal.payAndCheckout(tech, "WRONG");
📄 Output

After each purchase:

Receipt is saved to file:
Grocery_Check_1.txt
Tech_Check_2.txt
Console message:
Succesfull purchase in Silpo. RECEIPT #1 is saved!
🧮 Discount Logic
Store	Condition	Discount
GroceryStore	> 500 грн	5%
GroceryStore	Promo FOOD20	20%
TechStore	> 10000 грн	1000 грн
TechStore	Promo TECH10	10%
🛠️ Build & Run
Compile:
g++ main.cpp Store.cpp -o shop
Run:
./shop
📁 Project Structure
shop/
├── main.cpp
├── Store.h
├── Store.cpp
├── README.md
🎯 Concepts Demonstrated
Inheritance & Polymorphism
Abstract classes
Encapsulation
File I/O (fstream)
STL (vector, string)
💡 Possible Improvements
Add user input (interactive mode)
Support for multiple receipts history
Add new store types (e.g., clothing, pharmacy)
Implement taxes
Use smart pointers instead of raw pointers
👨‍💻 Author
Onufryk Ostap & Oleg Pona
Developed as a C++ OOP practice project.
