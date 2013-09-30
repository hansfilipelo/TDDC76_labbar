/*
FILNAMN: 		monetary_error.cc
LABORATION:		
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-09-26
BESKRIVNING:	
*/


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