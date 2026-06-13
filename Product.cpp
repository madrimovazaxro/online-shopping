#include "Product.h"

#include <iostream>

using namespace std;


//Constructors

Product::Product()
{
    productID = 0;

    name = "Unknown";

    category = "Unknown";

    price = 0;

    stock = 0;
}


Product::Product(
    int id,
    string name,
    string category,
    double price,
    int stock
)
{
    // ID validation
    if (id <= 0)
    {
        productID = 0;
    }
    else
    {
        productID = id;
    }


    this->name = name;

    this->category = category;


    // Prevent negative prices
    if (price < 0)
    {
        this->price = 0;
    }
    else
    {
        this->price = price;
    }


    // Prevent negative stock
    if (stock < 0)
    {
        this->stock = 0;
    }
    else
    {
        this->stock = stock;
    }
}


// Destructor

Product::~Product()
{

}


// Display

void Product::display()
{
    cout
        << "\n====== PRODUCT ======\n";

    cout
        << "ID: "
        << productID
        << endl;

    cout
        << "Name: "
        << name
        << endl;

    cout
        << "Category: "
        << category
        << endl;

    cout
        << "Price: $"
        << price
        << endl;

    cout
        << "Stock: "
        << stock
        << endl;
}


// Update
void Product::updateStock(
    int stock
)
{
    if (stock >= 0)
    {
        this->stock =
            stock;
    }
    else
    {
        cout
            << "Invalid stock value.\n";
    }
}


// Search 

bool Product::search(
    string keyword
)
{
    return (
        keyword
        ==
        name
        );
}


//Set price

void Product::setPrice(
    double price
)
{
    if (price >= 0)
    {
        this->price =
            price;
    }
}


//Set stock

void Product::setStock(
    int stock
)
{
    if (stock >= 0)
    {
        this->stock =
            stock;
    }
}


//Getters

int Product::getID() const
{
    return productID;
}


string Product::getName() const
{
    return name;
}


string Product::getCategory() const
{
    return category;
}


double Product::getPrice() const
{
    return price;
}


int Product::getStock() const
{
    return stock;
}