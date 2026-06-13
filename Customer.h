#pragma once
#include <iostream>
#include <vector>
#include "User.h"
#include "Cart.h"
#include "Order.h"
#include "Product.h"
using namespace std;
//inheretence
class Customer : public User
{
private:
    //Composition
    Cart cart;
    vector<Order> orderHistory;
    static int customerCount;
public:
    Customer();
    Customer(int id, string name, string pass );
    ~Customer() override;
    void browserProducts();
    void addToCart( Product product, int quantity);
    void removeFromCart( int productID );
    void checkout();
    void viewOrders();
    void menu() override;
    void setCart( Cart cart );
    Cart getCart();
};