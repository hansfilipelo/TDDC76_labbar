/*
FILNAMN: 		monetary_error.cc
LABORATION:		2
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-09-26
BESKRIVNING:	Implementation file for error class monetary_error
*/


#ifndef monetary_errorfile
#define monetary_errorfile
#include <stdexcept>
#include <string>
using namespace std;

class monetary_error : public logic_error
{
public:
    explicit monetary_error(const string& what_arg) noexcept
    : logic_error{what_arg} {}
    
    explicit monetary_error(const char* what_arg) noexcept
    : logic_error{what_arg} {}
};

#endif