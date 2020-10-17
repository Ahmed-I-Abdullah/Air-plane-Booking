#include "Seat.h"

#include <iostream>

#include <ostream>


using namespace std;

Seat::Seat()
{
    seat_number = 0;
    seat_letter = ' ';
}

Seat::Seat(int seat_num, char seat_character)
{
    seat_number = seat_num;
    seat_letter = seat_character;
}

int Seat::get_seat_number() const
{
    return seat_number;
}

char Seat::get_seat_letter() const
{

    return seat_letter;
}

void Seat::set_seat_number(int seat_num)
{

    seat_number = seat_num;
}

void Seat::set_seat_letter(char seat_character)
{
    seat_letter = seat_character;
}
