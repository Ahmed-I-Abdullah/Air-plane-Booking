

#ifndef Seat_Included
#define Seat_Included

class Seat
{
public:
    Seat();
	//default constructor
    // PROMISES: initializes the seat_number part and the seat_letter part of a Seat object
    // with 0 and a space (' ') respectively.

    Seat(int seat_num, char seat_character);
    // PROMISES: initializes the sezt_number part and the seat_letter part of a Seat object
    // with the supplied values of seat_num and seat_character respectively.

    int get_seat_number() const;
    // PROMISES: returns the number part of a Seat object

    char get_seat_letter() const;
    // PROMISES: returns the letter part of a seat object

    void set_seat_number(int seat_num);
    // PROMISES: sets a new value to number part of a Seat object with the
    //           value of seat_num.


    void set_seat_letter(char seat_character);
    // PROMISES: sets a new value to charcter part of a Seat object with the
    //           value of seat_character.


private:
    int seat_number;
    char seat_letter;
};

#endif