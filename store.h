#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Product {
    std::string name;
    double price;
};

class Store {
protected:
    std::string storeName;
    std::string promoCode;
    double promoDiscountRate;

public:
    Store(std::string name, std::string promo, double discount);
    virtual ~Store() = default;

    std::string getName() const;

    double getPromoDiscount(const std::string& inputCode) const;

    // Віртуальні методи
    virtual double calculateStoreDiscount(double totalSum) const = 0;
    virtual void generateReceipt(int receiptId, const std::vector<Product>& cart, double total, double finalSum) const = 0;
};

// ФІЛІЯ 1: Продуктовий
class GroceryStore : public Store {
public:
    GroceryStore();
    double calculateStoreDiscount(double totalSum) const override;
    void generateReceipt(int receiptId, const std::vector<Product>& cart, double total, double finalSum) const override;
};

// ФІЛІЯ 2: Магазин техніки
class TechStore : public Store {
public:
    TechStore();
    double calculateStoreDiscount(double totalSum) const override;
    void generateReceipt(int receiptId, const std::vector<Product>& cart, double total, double finalSum) const override;
};

// СПІЛЬНА КАСА
class SelfCheckout {
private:
    std::vector<Product> cart;
    int receiptCounter;

public:
    SelfCheckout();
    void scanProduct(std::string name, double price);
    void clearCart();

    void payAndCheckout(Store* currentStore, std::string enteredPromo = "");
};