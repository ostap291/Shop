#include "Store.h"

using namespace std;

int main() {
    SelfCheckout terminal;

    Store* grocery = new GroceryStore();
    Store* tech = new TechStore();

    terminal.scanProduct("Bread", 30.0);
    terminal.scanProduct("Milk", 45.0);
    terminal.scanProduct("Coffee", 450.0);

    // застосовуємо промокод.
    terminal.payAndCheckout(grocery, "FOOD20");

    terminal.scanProduct("Laptop", 25000.0);
    terminal.scanProduct("Mouse", 1200.0);

    // промокод неправильний.
    terminal.payAndCheckout(tech, "WRONG");

    delete grocery;
    delete tech;

    return 0;
}