#pragma once
#include <string>
#include "User.h"
#include "Product.h"

using namespace std;

//inheretance
class Admin : public User {
private:
    static int adminCount; 
public:
    // Constructors
    Admin();
    Admin(int id, string user, string pass);
    // Destructor
    ~Admin() override; //polymorphism
    // Functions
    void addProduct(const Product& product); 
    void deleteProduct(int productID);
    void editProduct(int productID);
    void viewProducts(); 
    void viewOrders();
    void menu() override; 
};