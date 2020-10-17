
#include "Seat.h"

#include "Passenger.h"

#include "Flight.h"

#include "Final_Project.h"

#include <fstream>

#include <iostream>

#include <cstdlib>

#include <string>

#include <vector>

#include <limits>

#include <cstring>


using namespace std;

char* trim_white_space(char* str)
{
    char* end;

    while (isspace((unsigned char)*str))
        str++;

    if (*str == 0)
        return str;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    end[1] = '\0';

    return str;
}


void display_header()
{
    cout
        << "Version: 1.0\nTerm Project- Flight Managment Program in C++\nProduced by:Ahmed Abdullah"
        << endl;
}


void clean_Standard_Input_Stream(void)
{
    int leftover;
    do
    {
        leftover = cin.get();
    } while (leftover != '\n' && leftover != EOF);
}


void press_Enter()
{
    cout << "\n<<< Press Return to Continue>>>>\n";
    cin.get();
}


int main()
{
    int menu_selection, error_counter=0;
    string my_file;
    cout << "Please enter the name of the file including the passengers data: ";
    getline(cin, my_file);
    Flight my_flight;
    my_flight.populate_flight_from_file(my_file);
    display_header();
    press_Enter();
    press_Enter();

    while (menu_selection != 6)
    {

        cout << "\n\n Please select one of the following options:";

        cout << "\n 1. Display Flight Seat Map.";

        cout << "\n 2. Display Passengers Information.";

        cout << "\n 3. Add a New Passenger.";

        cout << "\n 4. Remove an Existing Passenger";

        cout << "\n 5. Save data";

        cout << "\n 6. Quit.";

        while (true)
        {
            cout << "\n\n Enter your choice: (1, 2, 3, 4, 5, or 6):";
            if (cin >> menu_selection)
            {
                if (menu_selection == 1 || menu_selection == 2 || menu_selection == 3
                    || menu_selection == 4 || menu_selection == 5 || menu_selection == 6)
                {
                    error_counter = 0;
                    cout << "\n\n";
                    break;
                }

                else
                {
                    cout << "\nInput incorrect! Please enter a number between 1-6\n";
                    clean_Standard_Input_Stream();
                }
            }

            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInput incorrect! Please enter a number between 1-6\n";
            }

            error_counter++;
            if (error_counter >= 3)
            {
                cout << "\nToo many wrong inputs.Program Terminating";
                exit(1);
            }
        }


        switch (menu_selection)
        {
            case 1:
                my_flight.display_flight_map();
                clean_Standard_Input_Stream();
                press_Enter();
                break;
            case 2:
                my_flight.display_passengers();
                clean_Standard_Input_Stream();
                press_Enter();
                break;
            case 3:
                my_flight.add_passenger();
                break;
            case 4:
                my_flight.remove_passenger();
                break;
            case 5:
                my_flight.save_info(my_file);
                break;
            case 6:
                cout << "\nProgram Terminated";
                exit(1);
                break;
        }
    }
    return 0;
}
