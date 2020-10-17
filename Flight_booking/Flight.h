#include <string>
#include <vector>


#ifndef Flight_Included
#define Flight_Included

class Flight
{
public:
    Flight();
	// Default constructor
    // PROMISES: initializes the flight num with an empty string ie ("")
    // Initializes rows_number and seats per row with 0
    // Creates a vector of passengers with size 0

    Flight(std::string fly_number, int plane_rows, int Plane_seats_Prow,
        std::vector<Passenger>& flight_list);
    // PROMISES: initializes the flight num with fly_number
    // Initializes rows_number and seats per row with plane_rows and Plane_seats_Prow respectively
    // Assigns a vector of passengers with the given flight_list
	
	void set_flight_num(std::string fli_number);
    // PROMISES: sets a new value to flight number part of a Flight object with the
    //           value of fli_number.


    void set_plane_rows(int r_plane);
    // PROMISES: sets a new value to number of rows part of a Flight object with the
    //           value of r_plane.


    void set_seats_prow(int s_plane);
    // PROMISES: sets a new value to number of seats per row (Seats_Per_Row) part of a Flight object with the
    //           value of s_plane.

    std::string get_flight_number();
    // PROMISES: returns the flight number in a Flight object

    int get_plane_rows();
    // PROMISES: returns the number of rows in a Flight object

    int get_seats_prow();
    // PROMISES: returns the number of seats per row in a Flight object


    void display_passengers();
    // PROMISES: Prints the passenger information in a table on the console
	// Each passenger is printed in a seprate line with a good looking format
	// and all information is on one line

    void add_passenger();
    // PROMISES:asks the user to enter a passenger information to the console
	// Shows error if user enters invalid data 
    // Add a passenger with the entered infromation to the end of the list


    void remove_passenger();
    // PROMISES: Asks the user to enter the id of a passenger to be removed
    // from the list and if a passenger with the provided id exists in the list
    // removes it, otherwise shows an error message

    void display_flight_map();
    // PROMISES: shows the plane seat map with its number of rows and seat per row
    // and indicates reserved seats with an X

    void save_info(std::string s_in);
    // REQUIRMENTS: A string containing the filepath to the file to which the information
    // should be saved
    // PROMISES: opens the file s_in
	// Saves the flight information on the first line then the passenger information in a table format in the given file
	// Closes the file


    void populate_flight_from_file(std::string read_file);
    // REQUIRMENTS: A string containing the filepath to the file which contains
    // the passengers information
    // PROMISES: Opens the file named read_file and gives an error if it does not exist 
    // Fills the Flight object with the information in the text file
	// Closes the file


private:
    std::string flight_num;
    int rows_number;
    int Seats_Per_Row;
    std::vector<Passenger> p_list;
};


#endif