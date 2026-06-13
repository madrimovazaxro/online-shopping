#include "Order.h"
#include <iostream>
using namespace std;
//Constructors
Order::Order()
{
    orderID = 0;

    customerName = "Unknown";

    totalAmount = 0;

    orderDate = "Not Set";
}
Order::Order(int id, const string& customer, double total)
{
    orderID = id;
    customerName = customer;
    // Prevent invalid totals
    if (total < 0)
    {
        totalAmount = 0;
    }
    else
    {
        totalAmount = total;
    }
    // Placeholder date
    orderDate = "Current Order";
}
//Destructor
Order::~Order()
{
}
//Generate  Bill
void Order::generateBill()
{
    cout
        << "\n====== BILL ======\n";
    cout
        << "Order ID: "
        << orderID
        << endl;

    cout
        << "Customer: "
        << customerName
        << endl;

    cout
        << "Date: "
        << orderDate
        << endl;

    cout
        << "Total Amount: $"
        << totalAmount
        << endl;
}
//Display order
void Order::displayOrder()
{
    cout << "Order ID: " << orderID << endl;
    cout << "Customer: " << customerName << endl;
    cout<< "Total Amount: $"<< totalAmount<< endl;
    cout<< "Date: "<< orderDate << endl;
}
//Set Total
void Order::setTotal(double total )
{
    if (total >= 0)
    {
        totalAmount = total;
    }
}
//Getters
double Order::getTotal() const
{
    return totalAmount;
}
int Order::getOrderID() const
{
    return orderID;
}
string Order::getCustomerName() const
{
    return customerName;
}
string Order::getOrderDate() const
{
    return orderDate;
}