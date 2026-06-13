#pragma once
#include <string>
using namespace std;
class User
{
protected:
    int userID;
    string username;
    string password;
    string role;
public:
    //Default Constructor
    User();
    //Parametrized Constructor
    User(int id, const string& user, const string& pass, const string& role );
    // Virtual destructor
    virtual ~User(); //inheretence
    // Functions
    bool login(const string& user, const string& pass); //for safety
    void logout();
    // Pure virtual function - runtime polymorphism
    virtual void menu() = 0;
    // Setters
    void setUsername( const string& user); 
    void setPassword( const string& pass);
    // Getters
    string getUsername() const;
    string getRole() const;
    int getID() const;
    string getPassword() const;
};