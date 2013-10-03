/*
 FILNAMN: 		Monetary.cc
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

money::money(){
	currency = "unspecified";
	units = 0;
	cents = 0;
}

//------------------------------------

money::money(const std::string currCode, const int unitValue, const int centValue){
	if ( currCode.length() != 3 ){
		throw monetary_error{"En förkortning mÃ¥ste vara tre tecken lång"};
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

money& money::operator ++ (){
	cents = cents + 1;
	if ( cents >= 100 ){
		units = units + 1;
		cents = cents - 100;
	}
	
	return *this;
}

//------------------------------------

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

bool money::operator != (const money& otherMoney){
	
	if ( *this == otherMoney ){
		return false;
	}
	
	return true;
}

//------------------------------------

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

string money::getCurrency() const{
    
    return currency;
}

//------------------------------------

int money::getUnits() const{
    return units;
}

//------------------------------------

int money::getCents() const{
    return cents;
}

//------------------------------------

money& money::operator += (const money& otherMoney) {	
	*this = *this + otherMoney;
	
	return *this;
}


//------------------------------------

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


namespace monetary {
	void operator >> (istream& input){
		
		if ( (input.peek() >= '0') && (input.peek() <= '9') ){
			double x;
			input >> x;
			units = 
		
		
				
	}

//------------------------------------
    ostream& operator << (ostream& stream, const money& outsideMoney){
        
        if(outsideMoney.getCurrency() == "unspecified"){
            return stream << outsideMoney.getUnits() << "." << outsideMoney.getCents();
        }
        return stream << outsideMoney.getCurrency() << " " << outsideMoney.getUnits() << "." << outsideMoney.getCents();
    }
}

//------------------------------------

void money::print(ostream& output) const{
    output << *this;
}




