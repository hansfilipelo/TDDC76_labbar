/*
 FILNAMN: 		monetary_error.h
 LABORATION:
 PROGRAMMERARE:	hanel742, eriek984
 DATUM:			2013-09-26
 BESKRIVNING:
 */

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>


class momentary_error : public logic_error
{
    
public:
    explicit out_of_range(const string& what_arg) noexcept: logic_error{what_arg} {}
    explicit out_of_range(const char* what_arg) noexcept: logic_error{what_arg} {}
};