/*
 FILNAMN: 		Monetary.cc
 LABORATION:	2
 PROGRAMMERARE:	hanel742, eriek984
 DATUM:			2013-09-26
 BESKRIVNING:	Implementation file for class money
 */

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include "./Monetary.h"

using namespace monetary;
using namespace std;


//------------------------------------
// Helper function
// Checks if otherMoney and this money has same currency or if one of them is unspecified

void money::currencyCheck (const money& otherMoney) {
	if ( (currency != "unspecified") && (otherMoney.getCurrency() != "unspecified") ){
		if ( otherMoney.getCurrency() != currency ) {
			throw monetary_error{"Ej samma valutakod"};
		}
	}
}


//------------------------------------
// Constructor without in-values

money::money(){
	currency = "unspecified";
	units = 0;
	cents = 0;
}

//------------------------------------
// Constructor for inserting all given values

money::money(const std::string currCode, const int unitValue, const int centValue){
	if ( currCode.length() != 3 ){
		throw monetary_error{"En valutaförkortning måste vara tre tecken lång"};
	}
	if ( unitValue < 0 ){
		throw monetary_error{"Du måste ge positiva värden på beloppet"};
	}
	if ( centValue < 0 || centValue > 99 ){
		throw monetary_error{"Centvärde måste ligga mellan 0 och 99"};
	}
    
	currency = currCode;
	units = unitValue;
	cents = centValue;
}

//------------------------------------
// Constructor for values but unspecified curr code

money::money(const int unitValue, const int centValue){
	if ( unitValue < 0 ){
		throw monetary_error{"Du måste ge positiva värden på beloppet"};
	}
	if ( centValue < 0 || centValue > 99 ){
		throw monetary_error{"Centvärde måste ligga mellan 0 och 99"};
	}
	
	currency = "unspecified";
	units = unitValue;
	cents = centValue;
}

//------------------------------------
// Constructor for curr code but no values

money::money(const string currCode){
	if ( currCode.length() != 3 ){
        throw monetary_error{"valutaförkortning måste vara tre tecken"};
	}
	
	currency = currCode;
	units = 0;
	cents = 0;
}

//------------------------------------
// Copy-constructor

money::money(const money& otherMoney){
	
	currency = otherMoney.getCurrency();
	units = otherMoney.getUnits();
	cents = otherMoney.getCents();
}


//------------------------------------
// = operator

money& money::operator = (const money& otherMoney){

    // If both objects have defined currency but they are not the same - do mtf error.
    currencyCheck(otherMoney);
    
    // Essentially only two cases except error
    if ( currency == "unspecified"){
        currency = otherMoney.getCurrency();
        units = otherMoney.getUnits();
        cents = otherMoney.getCents();
    }
    else {
        units = otherMoney.getUnits();
        cents = otherMoney.getCents();
    }
    
	return *this;
}

//------------------------------------
// Smaller than (<) operator

bool money::operator < (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
    currencyCheck(otherMoney);
    
    
    if ( units < otherMoney.getUnits() ){
        return true;
    }
    else if ( (units == otherMoney.getUnits()) && (cents < otherMoney.getCents()) ){
        return true;
    }
    else {
        return false;
    }
}

//------------------------------------
// Bigger than (>) operator

bool money::operator > (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
    currencyCheck(otherMoney);
    
    
    if ( units > otherMoney.getUnits() ){
        return true;
    }
    else if ( (units == otherMoney.getUnits()) && (cents > otherMoney.getCents()) ){
        return true;
    }
    else {
        return false;
    }
}

//------------------------------------
// == comparator

bool money::operator == (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
    currencyCheck(otherMoney);
    
    if ( units == otherMoney.getUnits() && cents == otherMoney.getCents() ){
        return true;
    }
    else {
        return false;
    }
}

//------------------------------------
// + operator

money&& money::operator + (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
   currencyCheck(otherMoney);
    
    int unitSum;
    int centSum;
    unitSum= units + otherMoney.getUnits();
    centSum = cents + otherMoney.getCents();
    if (centSum >= 100 ){
        unitSum = unitSum + 1;
        centSum = centSum - 100;
    }
    
    if ( (currency == "unspecified") && (otherMoney.getCurrency() == "unspecified") ){
        return move(money("unspecified", unitSum, centSum));
    }
    else if (currency == "unspecified"){
        return move(money(otherMoney.getCurrency(), unitSum, centSum));
    }
    else {
        return move(money(currency, unitSum, centSum));
    }
    
}

//------------------------------------
// - operator

money&& money::operator - (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
   currencyCheck(otherMoney);
    
    int unitSum;
    int centSum;
    unitSum= units - otherMoney.getUnits();
    centSum = cents - otherMoney.getCents();
    if ( centSum < 0 ){
	    centSum = 100 + centSum;
	    unitSum = unitSum - 1;
    }
    // Throw if unitSum is less than zero
    if ( unitSum < 0 ){
	    throw monetary_error{"Subtraktion resulterar i negativt belopp - ej tillåtet!"};
    }
    
    if (centSum >= 100 ){
        unitSum = unitSum + 1;
        centSum = centSum - 100;
    }
    
    if ( (currency == "unspecified") && (otherMoney.getCurrency() == "unspecified") ){
        return move(money("unspecified", unitSum, centSum));
    }
    else if (currency == "unspecified"){
        return move(money(otherMoney.getCurrency(), unitSum, centSum));
    }
    else {
        return move(money(currency, unitSum, centSum));
    }
    
}

//------------------------------------
// ++ pre operator

money& money::operator ++ (){
	cents = cents + 1;
	if ( cents >= 100 ){
		units = units + 1;
		cents = cents - 100;
	}
	
	return *this;
}

//------------------------------------
// ++ post operator

money money::operator ++ (int){
    
    money temp( *this );
	
	cents = cents + 1;
	if ( cents >= 100 ){
		units = units + 1;
		cents = cents - 100;
	}
	
	return temp;
	
}

//------------------------------------
// Comparator !=

bool money::operator != (const money& otherMoney){
	
	if ( *this == otherMoney ){
		return false;
	}
	
	return true;
}

//------------------------------------
// Comparator >=

bool money::operator >= (const money& otherMoney){
	
	if ( *this == otherMoney ){
		return true;
	}
	else if ( *this > otherMoney ){
		return true;
	}
	
	return false;
}

//------------------------------------
// comparator <=

bool money::operator <= (const money& otherMoney){
	
	if ( *this == otherMoney ){
		return true;
	}
	else if ( *this < otherMoney ){
		return true;
	}
	
	return false;
}

//------------------------------------
// Gets currency who is private variable.

string money::getCurrency() const{
    
    return currency;
}

//------------------------------------
// Gets units who is private variable.

int money::getUnits() const{
    return units;
}

//------------------------------------
// Gets cents who is private variable. 

int money::getCents() const{
    return cents;
}

//------------------------------------
// Sets cuurency who is private variable. 

void money::setCurrency(const string currCode){
    currency = currCode;
}

//------------------------------------
// Sets units who is private variable. 

void money::setUnits(const int unitValue){
    units = unitValue;
}

//------------------------------------
// Sets cents who is private variable. 

void money::setCents(const int centValue){
    cents = centValue;
}

//------------------------------------
// += operator

money& money::operator += (const money& otherMoney) {	
	*this = *this + otherMoney;
	
	return *this;
}


//------------------------------------
// -= operator

money& money::operator -= (const money& otherMoney) {	
	*this = *this - otherMoney;
	
	return *this;
}

//------------------------------------

money& money::operator -- (){
	cents = cents - 1;
	if ( cents < 0 ){
		units = units - 1;
		cents = 100 + cents;
	}
	
	// Throw if units is less than zero
	if ( units < 0 ){
		throw monetary_error{"Subtraktion resulterar i negativt belopp - ej tillåtet!"};
	}
	
	return *this;
}

//------------------------------------
// -- operator- 

money money::operator -- (int){
    
    money temp( *this );
    
    cents = cents - 1;
    if ( cents < 0 ){
	    units = units - 1;
	    cents = cents + 100;
    }
    // Throw if units is less than zero
    if ( units < 0 ){
	    throw monetary_error{"Subtraktion resulterar i negativt belopp - ej tillåtet!"};
    }
    
    return temp;
	
}

//------------------------------------
// Reader operator <<

// Friends not included in class - have to specify namespace
namespace monetary {
	istream& operator >> (istream& input, money& otherMoney){
		
		// If whitespaces before currency code - remove them
		if ( input.peek() == ' ' ){
			while ( input.peek() == ' ' ) {
				input.get();
			}
		}
		
		// If Curr code - read it. 
		if ( isalpha( input.peek() ) ) {
			string currCode;
			for (int i = 1 ; i <= 3 ; i++ ){
				if ( not (isalpha( input.peek() ))){
					throw monetary_error{"En valutaförkortning måste vara tre tecken lång"};
				}
				currCode += input.get();
			}
			if ( isalpha( input.peek() ) ){
				throw monetary_error{"En valutaförkortning måste vara tre tecken lång"};
			}
			
			otherMoney.setCurrency(currCode);
		}
		
		// If whitespaces before values - remove them
		if ( input.peek() == ' ' ){
			while ( input.peek() == ' ' ) {
				input.get();
			}
		}
		
		// If digits - read them
		if ( isdigit( input.peek() ) ){
		
			int unitValue;
			int centValue;
			double total;
			
			input >> total;
			
			if ( total < 0 ){
				throw monetary_error{"Du kan ej skicka in negativa värden!"};
			}
			
			unitValue = static_cast<int>(total);
			centValue = static_cast<int>(total*100)%100;
			
			otherMoney.setUnits(unitValue);
			otherMoney.setCents(centValue);
		}
		
		input.setstate(ios::eofbit);
		
		return input;
	}

//------------------------------------
// Print using operator <<

    ostream& operator << (ostream& stream, const money& outsideMoney){
        
        if(outsideMoney.getCurrency() == "unspecified"){
            return stream << outsideMoney.getUnits() << "." << outsideMoney.getCents();
        }
        return stream << outsideMoney.getCurrency() << " " << outsideMoney.getUnits() << "." << outsideMoney.getCents();
    }
}

//------------------------------------
// Print function

void money::print(ostream& output) const{
    output << *this;
}




