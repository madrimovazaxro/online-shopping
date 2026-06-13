#include "Admin.h"
#include "Database.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
int Admin::adminCount = 0;
// Constructors
Admin::Admin(): User()
{
    adminCount++;
}
Admin::Admin(int id, string user, string pass) : User(id, user, pass, "admin")
{
    adminCount++;
}
// Destructors
Admin::~Admin()
{
    adminCount--;
}
//Add Product
void Admin::addProduct(const Product& product)
{
    ofstream file("products.txt", ios::app);
    if (!file)
    {
        cout << "Cannot open products.txt\n";
        return;
    }
    //Writes into products.txt
    file
        << product.getID() << " "
        << product.getName() << " "
        << product.getCategory() << " "
        << product.getPrice() << " "
        << product.getStock()
        << endl;
    file.close();
    cout << "Product added successfully.\n";
}
// View Products
void Admin::viewProducts()
{
    Database db;

    vector<Product> products = db.loadProducts();

    if (products.empty())
    {
        cout << "No products available.\n";

        return;
    }

    cout << "\n====== PRODUCTS ======\n";
    for (int i = 0; i < (int)products.size(); i++)
    {
        products[i].display();
    }
}
//Delete Product
void Admin::deleteProduct(int productID)
{
    ifstream file("products.txt");
    ofstream temp("temp.txt");
    bool found = false;
    int id;
    string name;
    string category;
    double price;
    int stock;
    while (file>> id>> name >> category>> price>> stock)
    {
        if (id == productID)
        {
            found = true;
            continue;
        }
        temp << id << " " << name << " " << category << " " << price << " " << stock << endl;     
    }
    file.close();
    temp.close();
    remove("products.txt");
    rename("temp.txt","products.txt");
    if (found)
    {
        cout<< "Product deleted.\n";
    }
    else
    {
        cout<< "Product not found.\n";
    }
}
//Edit 
void Admin::editProduct(int productID)
    
{
    ifstream file("products.txt");
    ofstream temp("temp.txt" );
    int id;
    string name;
    string category;
    double price;
    int stock;
    bool found = false;
    while (file >> id >> name >> category >> price >> stock)
    {
        if (id == productID)
        {
            found = true;

            try
            {
                cout << "New name: ";
                cin >> name;

                cout << "New category: ";
                cin >> category;

                cout << "New price: ";
                cin >> price;

                if (cin.fail())
                {
                    throw "Numbers only.";
                }

                if (price <= 0)
                {
                    throw "Price must be positive.";
                }

                cout << "New stock: ";
                cin >> stock;

                if (cin.fail())
                {
                    throw "Numbers only.";
                }

                if (stock < 0)
                {
                    throw "Stock cannot be negative.";
                }
            }

            catch (const char* msg)
            {
                cin.clear();

                cin.ignore(1000,'\n');

                cout << msg << endl;

                return;
            }
        }

        temp << id << " " << name << " " << category << " " << price << " " << stock << endl;
    }
    file.close();
    temp.close();
    remove("products.txt");
    rename("temp.txt", "products.txt");
    if (found)
    {
        cout << "Product updated.\n";
    }
    else
    {
        cout << "Product not found.\n";
    }
}
//View Orders
void Admin::viewOrders()
{
    ifstream file("orders.txt");

    if (!file)
    {
        cout << "No orders file.\n";

        return;
    }

    string line;

    cout<< "\n====== ORDERS ======\n";

    bool empty = true;

    while (getline(file, line))
    {
        empty = false;
        cout << line << endl;
    }

    if (empty)
    {
        cout << "No orders yet.\n";
    }
}
//Menu
void Admin::menu()
{
    int choice = 0;

    do
    {
        try
        {
            cout << "\n====== ADMIN MENU ======\n";

            cout << "1. Add Product\n";
            cout << "2. Delete Product\n";
            cout << "3. Edit Product\n";
            cout << "4. View Products\n";
            cout << "5. View Orders\n";
            cout << "6. Logout\n";

            cout << "Choice: ";

            cin >> choice;

            if (cin.fail())
            {
                throw "Please enter numbers only.";
            }

            switch (choice)
            {
            case 1:
            {
                Database db;

                vector<Product> products = db.loadProducts();

                int id;
                string name;
                string category;
                double price;
                int stock;

                cout << "ID: ";
                cin >> id;

                if (cin.fail())
                    throw "Please enter numbers only.";

                if (id <= 0)
                    throw "ID must be positive.";

                for (int i = 0; i < (int)products.size();i++)
                {
                    if (products[i].getID()==id)
                    {
                        throw "Product ID already exists.";
                    }
                }

                cout << "Name: ";
                cin >> name;

                cout << "Category: ";
                cin >> category;

                cout << "Price: ";
                cin >> price;

                if (cin.fail())
                    throw "Please enter numbers only.";

                if (price <= 0)
                    throw "Price must be positive.";

                cout << "Stock: ";
                cin >> stock;

                if (cin.fail())
                    throw "Please enter numbers only.";

                if (stock < 0)
                    throw "Stock cannot be negative.";

                Product p(id, name, category, price, stock);

                addProduct(p);

                break;
            }

            case 2:
            {
                int id;

                cout << "Enter ID: ";

                cin >> id;

                if (cin.fail())
                    throw "Please enter numbers only.";

                deleteProduct(id);

                break;
            }

            case 3:
            {
                int id;

                cout << "Enter ID: ";

                cin >> id;

                if (cin.fail())
                    throw "Please enter numbers only.";

                editProduct(id);

                break;
            }

            case 4:

                viewProducts();

                break;

            case 5:

                viewOrders();

                break;

            case 6:

                logout();

                break;

            default:

                throw "Invalid option.";
            }
        }

        catch (const char* msg)
        {
            cin.clear();

            cin.ignore(1000, '\n');
 
            cout << msg << endl;
        }

    } while (choice != 6);
}