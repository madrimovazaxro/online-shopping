#include <iostream>
#include <fstream>

#include "Customer.h"
#include "Database.h"

using namespace std;


// Static

int Customer::customerCount = 0;


// Constructor

Customer::Customer()
    : User()
{
    customerCount++;
}

Customer::Customer(
    int id,
    string name,
    string pass
)
    : User(
        id,
        name,
        pass,
        "customer"
    )
{
    customerCount++;
}


// Destructor

Customer::~Customer()
{
    customerCount--;
}


// Browse Products

void Customer::browserProducts()
{
    Database db;

    vector<Product> productList =
        db.loadProducts();

    if (productList.empty())
    {
        cout
            << "No products available.\n";

        return;
    }

    cout
        << "\n======= PRODUCTS =======\n";

    for (
        int i = 0;
        i < (int)productList.size();
        i++
        )
    {
        productList[i].display();
    }
}


//Add to cart

void Customer::addToCart(
    Product product,
    int quantity
)
{
    cart.addItem(
        product,
        quantity
    );
}


// Remove

void Customer::removeFromCart(
    int productID
)
{
    cart.removeItem(
        productID
    );
}


// Checkout

void Customer::checkout()
{
    double total =
        cart.calculateTotal();

    if (total == 0)
    {
        cout
            << "Cart empty.\n";

        return;
    }

    Database db;

    vector<Product>
        products =
        db.loadProducts();

    vector<Product>
        cartProducts =
        cart.getProducts();

    vector<int>
        quantities =
        cart.getQuantities();


    // stock update

    for (
        int i = 0;
        i < (int)cartProducts.size();
        i++
        )
    {
        for (
            int j = 0;
            j < (int)products.size();
            j++
            )
        {
            if (
                products[j].getID()
                ==
                cartProducts[i].getID()
                )
            {
                int newStock =
                    products[j].getStock()
                    -
                    quantities[i];

                if (newStock < 0)
                {
                    cout
                        << "Stock problem.\n";

                    return;
                }

                products[j].updateStock(
                    newStock
                );

                break;
            }
        }
    }


    db.saveProducts(
        products
    );


    vector<Order>
        orders =
        db.loadOrders();

    int newID =
        (int)orders.size() + 1;


    Order order(
        newID,
        getUsername(),
        total
    );

    orderHistory.push_back(
        order
    );


    ofstream file(
        "orders.txt",
        ios::app
    );

    if (!file)
    {
        cout
            << "Cannot open orders file.\n";

        return;
    }

    file
        << newID
        << " "
        << getUsername()
        << " ";


    for (
        int i = 0;
        i < (int)cartProducts.size();
        i++
        )
    {
        file
            << cartProducts[i].getName()

            << "(x"

            << quantities[i]

            << ") ";
    }

    file
        << "Total:"
        << total
        << endl;

    file.close();


    cout
        << "\nOrder completed.\n";

    cout
        << "Total payment: $"
        << total
        << endl;

    cart.clearCart();
}


//View Orders

void Customer::viewOrders()
{
    ifstream file(
        "orders.txt"
    );

    if (!file)
    {
        cout
            << "Could not open orders.\n";

        return;
    }

    string line;

    bool found = false;

    cout
        << "\n====== ORDER HISTORY ======\n";

    while (
        getline(
            file,
            line
        )
        )
    {
        if (line.find(getUsername())!= -1)
        {
            found = true;

            cout
                << line
                << endl;

            cout
                << "-----------------\n";
        }
    }

    if (!found)
    {
        cout
            << "No orders found.\n";
    }
}


//Menu

void Customer::menu()
{
    int choice = 0;

    do
    {
        try
        {
            cout
                << "\n====== CUSTOMER MENU ======\n";

            cout << "1. Browse Products\n";
            cout << "2. Add To Cart\n";
            cout << "3. Remove From Cart\n";
            cout << "4. View Cart\n";
            cout << "5. Checkout\n";
            cout << "6. View Orders\n";
            cout << "7. Logout\n";

            cout
                << "Enter choice: ";

            cin
                >> choice;

            if (cin.fail())
            {
                throw
                    "Please enter numbers only.";
            }


            switch (choice)
            {
            case 1:

                browserProducts();

                break;


            case 2:
            {
                Database db;

                vector<Product>
                    productList =
                    db.loadProducts();

                int id;
                int quantity;

                cout
                    << "Enter product ID: ";

                cin >> id;

                if (cin.fail())
                {
                    throw
                        "Please enter numbers only.";
                }


                cout
                    << "Enter quantity: ";

                cin
                    >> quantity;

                if (cin.fail())
                {
                    throw
                        "Please enter numbers only.";
                }

                if (quantity <= 0)
                {
                    throw
                        "Quantity must be positive.";
                }


                bool found = false;

                for (
                    int i = 0;
                    i < (int)productList.size();
                    i++
                    )
                {
                    if (
                        productList[i].getID()
                        ==
                        id
                        )
                    {
                        found = true;

                        if (
                            quantity
                    >
                            productList[i].getStock()
                            )
                        {
                            throw
                                "Not enough stock.";
                        }

                        addToCart(
                            productList[i],
                            quantity
                        );

                        break;
                    }
                }

                if (!found)
                {
                    throw
                        "Product not found.";
                }

                break;
            }


            case 3:
            {
                int id;

                cout
                    << "Enter ID: ";

                cin
                    >> id;

                if (cin.fail())
                {
                    throw
                        "Please enter numbers only.";
                }

                removeFromCart(
                    id
                );

                break;
            }


            case 4:

                cart.viewCart();

                break;


            case 5:

                checkout();

                break;


            case 6:

                viewOrders();

                break;


            case 7:

                logout();

                break;


            default:

                throw
                    "Invalid option.";
            }

        }

        catch (const char* msg)
        {
            cin.clear();

            cin.ignore(
                1000,
                '\n'
            );

            cout
                << msg
                << endl;
        }

    } while (choice != 7);
}


//Getters/Setters

void Customer::setCart(
    Cart cart
)
{
    this->cart = cart;
}

Cart Customer::getCart()
{
    return cart;
}