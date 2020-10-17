
#include <string>


#ifndef Passenger_Included
#define Passenger_Included

class Passenger
{
public:
    Passenger();
    // PROMISES: initializes the first_name , last_name and phone_number with an
    // empty string ie ("")
    // initializes s_num with the seat defalut constructor and passenger_id with 0.

    Passenger(std::string string_one, std::string string_two, std::string string_three, int n_seat,
        char c_seat, int passenger_identification);
    // PROMISES: initializes the first_name with string_one , last_name with string_two and
    // phone_number with string_three
    // initializes the number part of the Seat object with n_seat and  the character part with
    // c_seat
    // initializes passenger_id with the value of passenger_identification.

    std::string get_first_name() const;
    // PROMISES: returns the first name in a passenger object

    std::string get_last_name() const;
    // PROMISES: returns the last name in a passenger object


    std::string get_phone_number() const;
    // PROMISES: returns the phone number in a passenger object


    Seat get_seat() const;
    // PROMISES: returns the Seat object in a passenger object

    int get_id() const;
    // PROMISES: returns the id in a passenger object


    void set_first_name(std::string string_one);
    // PROMISES: sets a new value to first_name part of a Passenger object with the
    //           value of string_one.

    void set_last_name(std::string string_two);
    // PROMISES: sets a new value to last_name part of a Passenger object with the
    //           value of string_two.


    void set_phone_number(std::string string_three);
    // PROMISES: sets a new value to phone_number part of a Passenger object with the
    //           value of string_three.


    void set_seat_num(int seat_num, char seat_character);
    // PROMISES: sets a new value to number part of a Seat object inside of a Passenger object with
    // the
    //           value of seat_num and sets a new value to letter part of a Seat object inside of a
    //           Passenger object with the value of seat_character.


    void set_id(int pass_id);
    // PROMISES: sets a new value to id part of a Passenger object with the
    //           value of pass_id.


private:
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    Seat s_num;
    int passenger_id;
};

#endif
