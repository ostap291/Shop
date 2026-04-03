#include "Store.h"

using namespace std;

Store::Store(string name, string promo, double discount) {
    storeName = name;
    promoCode = promo;
    promoDiscountRate = discount;
}

string Store::getName() const { return storeName; }

double Store::getPromoDiscount(const string& inputCode) const {
    if (inputCode == promoCode) return promoDiscountRate;
    return 0.0;
}

GroceryStore::GroceryStore() : Store("Silpo", "FOOD20", 0.20) {} // 20% за промокодом

double GroceryStore::calculateStoreDiscount(double totalSum) const {
    if (totalSum > 500) return totalSum * 0.05; // 5% знижки, якщо сума більше 500
    return 0.0;
}

void GroceryStore::generateReceipt(int receiptId, const vector<Product>& cart, double total, double finalSum) const {
    string filename = "Grocery_Check_" + to_string(receiptId) + ".txt";
    ofstream file(filename);

    if (file.is_open()) {
        file << "=== " << storeName << " ===" << endl;
        file << "Food products" << endl;
        for (const auto& item : cart) {
            file << item.name << " - " << item.price << " грн" << endl;
        }
        file << "-------------------" << endl;
        file << "Starting sum: " << total << " грн" << endl;
        file << "TO PAY: " << finalSum << " грн" << endl;
        file.close();
    }
}

TechStore::TechStore() : Store("Comfy", "TECH10", 0.10) {} // 10% за промокодом

double TechStore::calculateStoreDiscount(double totalSum) const {
    if (totalSum > 10000) return 1000.0; // Знижка 1000 грн на дорогі покупки
    return 0.0;
}

void TechStore::generateReceipt(int receiptId, const vector<Product>& cart, double total, double finalSum) const {
    string filename = "Tech_Check_" + to_string(receiptId) + ".txt";
    ofstream file(filename);

    if (file.is_open()) {
        file << "*** " << storeName << " ***" << endl;
        file << "Electronics and gadgets" << endl;
        for (const auto& item : cart) {
            file << "> " << item.name << " : " << item.price << " грн" << endl;
        }
        file << "*******************" << endl;
        file << "TOGETHER: " << total << " грн" << endl;
        file << "FINAL AMOUNT: " << finalSum << " грн" << endl;
        file << "12 months warranty!" << endl;
        file.close();
    }
}

SelfCheckout::SelfCheckout() {
    receiptCounter = 1;
}

void SelfCheckout::scanProduct(string name, double price) {
    Product p;
    p.name = name;
    p.price = price;
    cart.push_back(p);
}

void SelfCheckout::clearCart() {
    cart.clear();
}

void SelfCheckout::payAndCheckout(Store* currentStore, string enteredPromo) {
    if (cart.empty()) {
        cout << "!" << endl;
        return;
    }

    double totalSum = 0;
    for (const auto& item : cart) {
        totalSum += item.price;
    }

    double storeDiscount = currentStore->calculateStoreDiscount(totalSum);
    double promoDiscount = totalSum * currentStore->getPromoDiscount(enteredPromo);

    double finalSum = totalSum - storeDiscount - promoDiscount;
    if (finalSum < 0) finalSum = 0;

    currentStore->generateReceipt(receiptCounter, cart, totalSum, finalSum);

    cout << "Succesfull purchase in " << currentStore->getName() << ". RECEIPT #" << receiptCounter << " is saved!" << endl;

    receiptCounter++;
    clearCart();
}