#include "Cart.h"
#include <iostream>
using namespace std;


//Constructor

Cart::Cart()
{

}


//Destructor

Cart::~Cart()
{

}


//Add item

void Cart::addItem(Product product,int quantity)
{
    try
    {
        if (quantity <= 0)
        {
            throw "Quantity must be positive.";
        }

        // If product already exists
        for (int i = 0;i < (int)products.size(); i++)
        {
            if (products[i].getID()==product.getID())
            {
                quantities[i] += quantity;

                cout<< "Quantity updated.\n";
                return;
            }
        }
        products.push_back(product);
        quantities.push_back(quantity);

        cout << product.getName()<< " added to cart.\n";
    }
    catch (const char* msg)
    {
        cout<< msg<< endl;
    }
}

//Remove Item

void Cart::removeItem(
    int productID
)
{
    for (int i = 0; i < (int)products.size();i++)
    {
        if (products[i].getID()==productID)
        {
            cout
                << products[i].getName()
                << " removed.\n";

            for (
                int j = i;
                j < (int)products.size() - 1;
                j++
                )
            {
                products[j] = products[j + 1];

                quantities[j] =
                    quantities[j + 1];
            }

            products.pop_back();

            quantities.pop_back();

            return;
        }
    }

    cout
        << "Product not found.\n";
}


//View Cart

void Cart::viewCart()
{
    if (products.empty())
    {
        cout
            << "Cart is empty.\n";

        return;
    }

    cout
        << "\n====== CART ======\n";

    for (
        int i = 0;
        i < (int)products.size();
        i++
        )
    {
        cout
            << "ID: "
            << products[i].getID()
            << endl;

        cout
            << "Name: "
            << products[i].getName()
            << endl;

        cout
            << "Quantity: "
            << quantities[i]
            << endl;

        cout
            << "Price: $"
            << products[i].getPrice()
            << endl;

        cout
            << "Subtotal: $"
            << products[i].getPrice()
            * quantities[i]
            << endl;

        cout
            << "-----------------\n";
    }

    cout
        << "Total: $"
        << calculateTotal()
        << endl;
}


//Total

double Cart::calculateTotal()
{
    double total = 0;

    for (
        int i = 0;
        i < (int)products.size();
        i++
        )
    {
        total +=
            products[i].getPrice()
            *
            quantities[i];
    }

    return total;
}


// Clear

void Cart::clearCart()
{
    products.clear();

    quantities.clear();

    cout
        << "Cart cleaned.\n";
}


//Getters

vector<Product> Cart::getProducts()
{
    return products;
}

vector<int> Cart::getQuantities()
{
    return quantities;
}