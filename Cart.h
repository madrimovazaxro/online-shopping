#pragma once
#include <iostream>
#include <vector>
#include "Product.h"

using namespace std;
class Cart {
private:
    vector<Product> products;
    vector<int> quantities;
public:
    // Constructor
    Cart();
    // Destructor
    ~Cart();
    // Functions
    void addItem(Product product, int quantity);
    void removeItem(int productID);
    void viewCart();
    double calculateTotal();
    void clearCart();
    vector<Product> getProducts();
    vector<int> getQuantities();
};