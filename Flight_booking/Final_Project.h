#include <string>
#include <vector>

#ifndef Final_Project
#define Final_Project

char* trim_white_space(char* str);
// REQUIRMENTS: str point to the begining of a c-string
// PROMISES: Returns a pointer to a c-string after removing spaces leading 
// and trailing spaces from the initial one

void display_header();
// Promises: Displays header conataining information about the program

void clean_Standard_Input_Stream(void);
// PROMISES:cleans the buffer when someone enters incorrect input.

void press_Enter();
// Promises: outputs the "Press Enter" statment and continues the program when
// enter is pressed

#endif