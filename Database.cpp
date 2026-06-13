#include "Database.h"

#include <fstream>
#include <iostream>

using namespace std;


//Constructor

Database::Database()
{
    productsFile =
        "products.txt";

    ordersFile =
        "orders.txt";
}


//Destructor

Database::~Database()
{

}


//Products

void Database::saveProducts(
    const vector<Product>& products
)
{
    ofstream file(
        productsFile
    );

    try
    {
        if (!file)
        {
            throw "Could not open products file.";
        }

        for (
            int i = 0;
            i < (int)products.size();
            i++
            )
        {
            file
                << products[i].getID()
                << " "

                << products[i].getName()
                << " "

                << products[i].getCategory()
                << " "

                << products[i].getPrice()
                << " "

                << products[i].getStock()
                << endl;
        }

        file.close();
    }

    catch (const char* msg)
    {
        cout
            << msg
            << endl;
    }
}


//Load products

vector<Product>
Database::loadProducts()
{
    vector<Product> products;

    ifstream file(
        productsFile
    );

    try
    {
        if (!file)
        {
            throw "Products file not found.";
        }

        int id;

        string name;

        string category;

        double price;

        int stock;

        while (
            file
            >> id
            >> name
            >> category
            >> price
            >> stock
            )
        {
            Product p(
                id,
                name,
                category,
                price,
                stock
            );

            products.push_back(
                p
            );
        }

        file.close();
    }

    catch (const char* msg)
    {
        cout
            << msg
            << endl;
    }

    return products;
}


//Save Orders

void Database::saveOrders(
    const vector<Order>& orders
)
{
    ofstream file(
        ordersFile
    );

    try
    {
        if (!file)
        {
            throw "Could not open orders file.";
        }

        for (
            int i = 0;
            i < (int)orders.size();
            i++
            )
        {
            file
                << orders[i].getOrderID()
                << " "

                << orders[i].getCustomerName()
                << " "

                << orders[i].getTotal()
                << endl;
        }

        file.close();
    }

    catch (const char* msg)
    {
        cout
            << msg
            << endl;
    }
}


//Load Orders

vector<Order>
Database::loadOrders()
{
    vector<Order> orders;

    ifstream file(
        ordersFile
    );

    try
    {
        if (!file)
        {
            throw "Orders file not found.";
        }

        int id;

        string customer;

        double total;

        while (
            file
            >> id
            >> customer
            >> total
            )
        {
            Order order(
                id,
                customer,
                total
            );

            orders.push_back(
                order
            );
        }

        file.close();
    }

    catch (const char* msg)
    {
        cout
            << msg
            << endl;
    }

    return orders;
}