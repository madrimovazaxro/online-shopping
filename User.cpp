#include "User.h"

#include <iostream>
#include <fstream>

using namespace std;


//Constructors

User::User()
{
    userID = 0;

    username = "";

    password = "";

    role = "";
}


User::User(
    int id,
    const string& user,
    const string& pass,
    const string& role
)
{
    userID = id;

    username = user;

    password = pass;

    this->role = role;
}


//Destructor

User::~User()
{

}


//Login

bool User::login(
    const string& user,
    const string& pass
)
{
    ifstream file(
        "users.txt"
    );

    if (!file)
    {
        cout
            << "Could not open users.txt\n";

        return false;
    }

    int id;

    string uname;

    string pword;

    string r;


    while (
        file
        >> id
        >> uname
        >> pword
        >> r
        )
    {
        if (
            user == uname
            &&
            pass == pword
            )
        {
            userID = id;

            username = uname;

            password = pword;

            role = r;

            file.close();

            return true;
        }
    }


    // Clear old values after failed login
    userID = 0;

    username = "";

    password = "";

    role = "";

    file.close();

    return false;
}


//Logout
void User::logout()
{
    cout
        << "Logged out successfully!"
        << endl;
}


//Setters

void User::setUsername(
    const string& user
)
{
    username = user;
}


void User::setPassword(
    const string& pass
)
{
    password = pass;
}


//Getters

string User::getUsername() const
{
    return username;
}


string User::getRole() const
{
    return role;
}


int User::getID() const
{
    return userID;
}


string User::getPassword() const
{
    return password;
}