#pragma once
#include <string>
using namespace std;

class Product
{
private:
    int productID;
    string name;
    string category;
    double price;
    int stock;
public:
    // Constructors
    Product();
    Product( int id, string name, string category, double price, int stock);
    // Destructor
    ~Product();
    // Functions
    void display();
    void updateStock( int stock );
    bool search( string keyword);
    // Setters
    void setPrice(double price);
    void setStock( int stock );
    // Getters
    int getID() const;
    string getName() const;
    string getCategory() const;
    double getPrice() const;
    int getStock() const;
};