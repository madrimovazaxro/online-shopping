#pragma once
#include <string>

using namespace std;
class Order
{
private:
    int orderID;
    string customerName;
    double totalAmount;
    string orderDate;
public:
    // Constructors
    Order();
    Order( int id, const string& customer, double total );
    // Destructor
    ~Order();
    // Functions
    void generateBill();
    void displayOrder();
    // Setter
    void setTotal(double total);
    // Getters
    double getTotal() const;
    int getOrderID() const;
    string getCustomerName() const;
    string getOrderDate() const;
};