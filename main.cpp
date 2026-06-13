#include <iostream>

#include "User.h"
#include "Customer.h"
#include "Admin.h"

using namespace std;

int main()
{
    int choice = 0;

    do //main loop - choice
    {
        try // if user fails to input int jump to catch
        {
            cout
                << "\n========== ONLINE SHOPPING SYSTEM ==========\n";

            cout
                << "1. Login\n";

            cout
                << "2. Exit\n";

            cout
                << "Enter choice: ";

            cin >> choice;

            if (cin.fail()) 
            {
                throw "Please enter numbers only.";
            }

            switch (choice)
            {
            case 1:
            {
                string username;
                string password;

                cout
                    << "Enter username: ";

                cin >> username;

                cout
                    << "Enter password: ";

                cin >> password;

                // login checker object
                Customer temp;

                if (
                    temp.login(
                        username,
                        password
                    )
                    )
                {
                    cout
                        << "\nLogin successful.\n";

                    User* currentUser; 

                    if (
                        temp.getRole()
                        ==
                        "admin"
                        )
                    {
                        currentUser =
                            new Admin(
                                temp.getID(),
                                temp.getUsername(),
                                temp.getPassword()
                            );

                        cout
                            << "Welcome Admin.\n";
                    }
                    else
                    {
                        currentUser =
                            new Customer(
                                temp.getID(),
                                temp.getUsername(),
                                temp.getPassword()
                            );

                        cout
                            << "Welcome Customer.\n";
                    }

                    

                    currentUser->menu(); 

                    delete currentUser;
                }
                else
                {
                    cout
                        << "\nInvalid username or password.\n";
                }

                break;
            }

            case 2:

                cout
                    << "\nProgram closed.\n";

                break;

            default:

                throw "Invalid menu choice.";
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
    }

    while (choice != 2);

    return 0;
}