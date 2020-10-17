#include "Seat.h"

#include "Passenger.h"

#include <iostream>

#include <string>

#include <ostream>


using namespace std;

Passenger::Passenger()
{
    first_name = "";
    last_name = "";
    phone_number = "";
    s_num = Seat();
    passenger_id = 0;
}


Passenger::Passenger(string string_one, string string_two, string string_three, int n_seat,
    char c_seat, int passenger_identification)
{

    first_name = string_one;
    last_name = string_two;
    phone_number = string_three;
    s_num = Seat(n_seat, c_seat);
    passenger_id = passenger_identification;
}


string Passenger::get_first_name() const
{
    return first_name;
}


string Passenger::get_last_name() const
{

    return last_name;
}


string Passenger::get_phone_number() const
{

    return phone_number;
}


Seat Passenger::get_seat() const
{

    return s_num;
}


int Passenger::get_id() const
{

    return passenger_id;
}


void Passenger::set_first_name(string string_one)
{

    first_name = string_one;
}


void Passenger::set_last_name(string string_two)
{

    last_name = string_two;
}


void Passenger::set_phone_number(string string_three)
{

    phone_number = string_three;
}


void Passenger::set_seat_num(int seat_num, char seat_character)
{

    s_num.set_seat_number(seat_num);
    s_num.set_seat_letter(seat_character);
}


void Passenger::set_id(int pass_id)
{
    passenger_id = pass_id;
}