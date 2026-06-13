#pragma once
#include <vector>
#include <string>
#include "Product.h"
#include "Order.h"

using namespace std;
class Database
{
private:
    string productsFile;
    string ordersFile;
public:
    // Constructor
    Database();
    // Destructor
    ~Database();
    //Products
    void saveProducts(const vector<Product>& products);
    vector<Product> loadProducts();
    //Orders
    void saveOrders( const vector<Order>& orders);
    vector<Order> loadOrders();
};