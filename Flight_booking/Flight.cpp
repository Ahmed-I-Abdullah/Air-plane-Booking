#include "Seat.h"

#include "Passenger.h"

#include "Flight.h"

#include "Final_Project.h"

#include <iomanip>

#include <fstream>

#include <iostream>

#include <string>

#include <vector>

#include <limits>

#include <cstring>

using namespace std;

Flight::Flight()
{
    flight_num = "";
    rows_number = 0;
    Seats_Per_Row = 0;
    p_list.resize(0);
}

Flight::Flight(
    string fly_number, int plane_rows, int Plane_seats_Prow, vector<Passenger>& flight_list)
{
    flight_num = fly_number;
    rows_number = plane_rows;
    Seats_Per_Row = Plane_seats_Prow;
    p_list = flight_list;
}

void Flight::set_flight_num(string fli_number)
{
    flight_num = fli_number;
}

void Flight::set_plane_rows(int r_plane)
{
    rows_number = r_plane;
}

void Flight::set_seats_prow(int s_plane)
{
    Seats_Per_Row = s_plane;
}

string Flight::get_flight_number()
{
    return flight_num;
}

int Flight::get_plane_rows()
{
    return rows_number;
}

int Flight::get_seats_prow()
{
    return Seats_Per_Row;
}

void Flight::populate_flight_from_file(string read_file)
{
    int row_counter = 0;
    string input_one, input_two, input_three, string_garbage;
    int seat_num, identification_number;
    char ch_seat;
    char input_one_array[20], input_two_array[20];

    ifstream in_file(read_file);

    if (in_file.fail())
    {
        cout << "Error opening file...quitting\n";
        exit(1);
    }

    in_file >> flight_num >> rows_number >> Seats_Per_Row;

    while (!in_file.eof())
    {
        getline(in_file, string_garbage, '\n');
        p_list.resize(++row_counter);
        in_file.get(input_one_array, 20);
        char* input_one_cleaned = trim_white_space(input_one_array);
        input_one = input_one_cleaned;
        in_file.get(input_two_array, 20);
        char* input_two_cleaned = trim_white_space(input_two_array);
        input_two = input_two_cleaned;
        in_file >> input_three >> seat_num >> ch_seat >> identification_number;

        if (in_file.fail())
        {
            p_list.resize(--row_counter);
            break;
        }
        p_list[row_counter - 1].set_first_name(input_one);
        p_list[row_counter - 1].set_last_name(input_two);
        p_list[row_counter - 1].set_phone_number(input_three);
        p_list[row_counter - 1].set_seat_num(seat_num, ch_seat);
        p_list[row_counter - 1].set_id(identification_number);
    }

    in_file.close();
}

void Flight::display_passengers()
{
    cout.width(20);
    cout << left << "First Name";
    cout.width(20);
    cout << left << "Last Name";
    cout.width(20);
    cout << left << "Phone";
    cout.width(7);
    cout << left << "row";
    cout.width(7);
    cout << left << "seat";
    cout.width(2);
    cout << left << "id\n";
    cout << "--------------------------------------------------------------------"
            "------------"
         << endl;
    for (long unsigned int i = 0; i < p_list.size(); i++)
    {
        cout.width(20);
        cout << left << p_list[i].get_first_name();
        cout.width(20);
        cout << left << p_list[i].get_last_name();
        cout.width(20);
        cout << left << p_list[i].get_phone_number();
        cout.width(7);
        cout << left << p_list[i].get_seat().get_seat_number();
        cout.width(7);
        cout << left << p_list[i].get_seat().get_seat_letter();
        cout.width(2);
        cout << left << p_list[i].get_id();
        cout << "\n----------------------------------------------------------------"
                "----------------"
             << endl;
    }
}

void Flight::add_passenger()
{
    int new_iden, seat_nmbr, match_check, error_counter = 0, error_counter1 = 0, error_counter2 = 0,
                                          error_counter3 = 0, empty_seat_check, user_choice;
    string first_name, last_name, phone_num;
    char seat_char;
    p_list.push_back(Passenger());

    while (true)
    {
        cout << "\nPlease enter the passenger id:";
        if (cin >> new_iden)
        {
            match_check = 0;
            for (long unsigned int i = 0; i < p_list.size(); i++)
            {
                if (p_list[i].get_id() == new_iden)
                    match_check = 1;
            }

            if (!match_check)
            {
                break;
            }
            else
            {
                cout << "A person with this id already exists. Please enter another "
                        "id.\n";
            }
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ID invalid. Please enter a numeric id\n";
        }

        error_counter++;
        if (error_counter >= 3)
        {
            cout << "\nToo many wrong inputs. Passenger has not been added. Please "
                    "try again later\n";
            p_list.pop_back();
            return;
        }
    }
    clean_Standard_Input_Stream();
    cout << "please enter the passenger first name:";
    getline(cin, first_name);
    if (first_name.length() > 20)
    {
        cerr << "Last name length is greater than field. The maximum number of "
                "letters will be stored\n";
        first_name.erase(20, first_name.length() - 20);
    }
    cout << "please enter the passenger last name:";
    getline(cin, last_name);
    if (last_name.length() > 20)
    {
        cerr << "Last name length is greater than field. The maximum number of "
                "letters will be stored\n";
        last_name.erase(20, last_name.length() - 20);
    }

    while (true)
    {
        cout << "\nPlease enter the passenger phone number:";
        if (getline(cin, phone_num))
        {
            if (phone_num.length() <= 12 && (phone_num[3] == '-' || phone_num[3] == ' ')
                && (phone_num[7] == '-' || phone_num[7] == ' '))
            {
                if (phone_num[3] == ' ')
                    phone_num[3] = '-';
                if (phone_num[7] == ' ')
                    phone_num[7] = '-';
                break;
            }
            else
            {
                cout << "Phone number invalid. Please enter a numer in the format "
                        "XXX-XXX-XXXX\n";
            }
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Phone number invalid. Please enter a numer in the format "
                    "XXX-XXX-XXXX\n";
        }

        error_counter1++;
        if (error_counter1 >= 3)
        {
            cout << "\nToo many wrong inputs. Passenger has not been added. Please "
                    "try again later\n";
            p_list.pop_back();
            return;
        }
    }
    while (true)
    {
        while (true)
        {
            cout << "\nEnter the passenger's desired row:";
            if (cin >> seat_nmbr)
            {
                if (seat_nmbr >= 0 && seat_nmbr <= rows_number)
                {
                    break;
                }
                else
                {
                    cout << "Input incorrect please enter a number between 0 and " << rows_number
                         << "\n";
                    clean_Standard_Input_Stream();
                }
            }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input incorrect please enter a number between 0 and " << rows_number
                     << "\n";
            }

            error_counter2++;
            if (error_counter2 >= 3)
            {
                cout << "\nToo many wrong inputs. Passenger has not been added. Please "
                        "try again later\n";
                p_list.pop_back();
                return;
            }
        }

        while (true)
        {
            cout << "\nEnter the passenger's desired seat:";
            if (cin >> seat_char)
            {
                if ((int)seat_char >= 97 && (int)seat_char <= 122)
                {
                    seat_char = (char)(seat_char - 32);
                }
                if ((seat_char - 'A') >= 0 && (seat_char - 'A') < Seats_Per_Row)
                {
                    break;
                }
                else
                {
                    cout << "Input incorrect please enter a seat letter between A and "
                         << (char)((Seats_Per_Row - 1) + 'A') << "\n";
                    clean_Standard_Input_Stream();
                }
            }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input incorrect please enter a seat letter between A and "
                     << (char)((Seats_Per_Row - 1) + 'A') << "\n";
            }

            error_counter3++;
            if (error_counter3 >= 3)
            {
                cout << "\nToo many wrong inputs. Passenger has not been added. Please "
                        "try again later\n";
                p_list.pop_back();
                return;
            }
        }
        empty_seat_check = 0;
        for (long unsigned int i = 0; i < p_list.size(); i++)
        {
            if (p_list[i].get_seat().get_seat_letter() == seat_char
                && p_list[i].get_seat().get_seat_number() == seat_nmbr)
                empty_seat_check = 1;
        }
        if (!empty_seat_check)
        {
            break;
        }

        cout << "\nSeat " << seat_nmbr << seat_char
             << " is already reserved please press 1 to choose another seat\nor "
                "press 2 to return to main menu\n";

        cin >> user_choice;
        if (user_choice == 2)
		{
			p_list.pop_back();
            return;
		}

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    p_list[p_list.size() - 1].set_id(new_iden);
    p_list[p_list.size() - 1].set_first_name(first_name);
    p_list[p_list.size() - 1].set_last_name(last_name);
    p_list[p_list.size() - 1].set_phone_number(phone_num);
    p_list[p_list.size() - 1].set_seat_num(seat_nmbr, seat_char);
}

void Flight::remove_passenger()
{
    int remove_ident, id_found = 0, error_counter=0;
    while (true)
    {
        cout << "Please enter the id of the passenger that needs to be removed:";
        if (cin >> remove_ident)
        {
            for (long unsigned int i = 0; i < p_list.size(); i++)
            {
                if (p_list[i].get_id() == remove_ident)
                {
                    p_list.erase(p_list.begin() + i);
                    id_found = 1;
                }
            }
            if (id_found)
            {
                break;
            }
            else
            {
                cout << "\nPassenger with id " << remove_ident
                     << " was not found in the list.Please enter another id\n";
					 

            }
        }
        else
        {
            cout << "\nID entered invalid. Please enter a numerical id.\n";
		     
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			
        }
		error_counter++;
		if(error_counter>=3)
		{
			cout<<"\nToo many wrong inputs. No passengers have been removed from list. Please try back later.\n";
			return;
		}
    }
}

void Flight::display_flight_map()
{
    char char_array[p_list.size()];
    int number_array[p_list.size()];
    for (long unsigned int i = 0; i < p_list.size(); i++)
    {
        char_array[i] = p_list[i].get_seat().get_seat_letter();
        number_array[i] = p_list[i].get_seat().get_seat_number();
    }
    int taken_seat_check, i, taken_counter;
    cout << "     ";
    for (int i = 0; i < Seats_Per_Row; i++)
    {
        cout << char('A' + i) << "   ";
    }
    cout << "\n";

    for (i = 0; i < rows_number + 1; i++)
    {
        cout << "   ";
        for (int j = 0; j < Seats_Per_Row; j++)
        {
            cout << "+---";
        }
        cout << "+";
        cout << "\n";
        if (i < 10)
        {
            cout << i << "  ";
        }
        else if (i >= 10 && i < 100)
        {
            cout << i << " ";
        }
        else
        {
            cout << i;
        }

        for (int j = 0; j <= Seats_Per_Row; j++)
        {
            cout << "| ";
            taken_counter = 0;
            for (int k = 0; char_array[k] != '\0'; k++)
            {
                taken_seat_check = 0;
                if (number_array[k] == i && j == char_array[k] - 'A')
                {
                    taken_seat_check = 1;
                    taken_counter++;
                }
                if (taken_seat_check)
                {
                    cout << "X";
                }
            }
            if (taken_counter)
            {
                cout << " ";
            }
            else
            {
                cout << "  ";
            }
        }

        cout << "\n";
    }
    cout << "   ";
    for (int j = 0; j < Seats_Per_Row; j++)
        cout << "+---";
    cout << "+";
}

void Flight::save_info(string s_in)
{
    char user_answer;
    int error_counter;
    while (true)
    {
        cout << "Do you want to save the data in the “flight_info.txt”? Please "
                "answer <Y or N>:";
        if (cin >> user_answer)
        {
            if (user_answer == 'y' || user_answer == 'Y' || user_answer == 'n'
                || user_answer == 'N')
            {
                break;
            }
            else
            {
                cout << "Input incorrect please enter Y or N\n";
                clean_Standard_Input_Stream();
            }
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input incorrect please enter Y or N\n";
        }

        error_counter++;
        if (error_counter >= 3)
        {
            cout << "\nToo many wrong inputs. Passengers data has not been saved. "
                    "Please try again later\n";
            return;
        }
    }
    if (user_answer == 'y' || user_answer == 'Y')
    {
        ofstream outfile(s_in);
        if (outfile.fail())
        {
            cout << "Error opening file...quitting\n";
            exit(1);
        }

        outfile << flight_num << "\t" << rows_number << "\t" << Seats_Per_Row << "\n";
        for (long unsigned int i = 0; i < p_list.size(); i++)
        {
            outfile.width(20);
            outfile << left << p_list[i].get_first_name();
            outfile.width(20);
            outfile << left << p_list[i].get_last_name();
            outfile.width(20);
            outfile << left << p_list[i].get_phone_number();
            outfile << left << p_list[i].get_seat().get_seat_number() << left
                    << p_list[i].get_seat().get_seat_letter() << "\t";
            outfile.width(20);
            outfile << left << p_list[i].get_id() << "\n";
        }
        cout << "\nAll the data in the passenger list was saved into the file " << s_in << ".\n";
        outfile.close();
        press_Enter();
    }
    else
        return;
}