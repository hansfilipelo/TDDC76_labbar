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
#include "./Monetary.h"

using namespace monetary;
using namespace std;

//------------------------------------

money::money(){
	string unspecified = "unspecified";
	currency = unspecified;
	units = 0;
	cents = 0;
}

//------------------------------------

money::money(const std::string currCode, const unsigned unitValue, const unsigned centValue){
        if ( currCode.length() != 3 ){
            throw monetary_error{"En fÃ¶rkortning mÃ¥ste vara tre tecken lÃ¥ng"};
        }
	currency = currCode;
	units = unitValue;
	cents = centValue;
}

//------------------------------------

money::money(const unsigned unitValue, const unsigned centValue){
	
	string unspecified = "unspecified";
	currency = unspecified;
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
	
	currency = otherMoney.currency;
	units = otherMoney.units;
	cents = otherMoney.cents;
}


//------------------------------------

money& money::operator = (const money& otherMoney){
	
    // If both objects have defined currency but they are not the same - do mtf error. 
    if ( (currency != "unspecified") && (otherMoney.currency != "unspecified") ){
        if ( otherMoney.currency != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
    // Essentially only two cases except error
    if ( currency == "unspecified"){
        currency = otherMoney.currency;
        units = otherMoney.units;
        cents = otherMoney.cents;
    }
    else {
        units = otherMoney.units;
        cents = otherMoney.cents;
    }

    
	return *this;
}

//------------------------------------

bool money::operator < (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
    if ( (currency != "unspecified") && (otherMoney.currency != "unspecified") ){
        if ( otherMoney.currency != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
    
    if ( units < otherMoney.units ){
        return true;
    }
    else if ( (units == otherMoney.units) && (cents < otherMoney.cents) ){
        return true;
    }
    else {
        return false;
    }
}

//------------------------------------

bool money::operator > (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
    if ( (currency != "unspecified") && (otherMoney.currency != "unspecified") ){
        if ( otherMoney.currency != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
    
    if ( units > otherMoney.units ){
        return true;
    }
    else if ( (units == otherMoney.units) && (cents > otherMoney.cents) ){
        return true;
    }
    else {
        return false;
    }
}

//------------------------------------

bool money::operator == (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
    if ( (currency != "unspecified") && (otherMoney.currency != "unspecified") ){
        if ( otherMoney.currency != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
    if ( units == otherMoney.units && cents == otherMoney.cents ){
        return true;
    }
    else {
        return false;
    }
}

//------------------------------------

bool money::operator != (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
    if ( (currency != "unspecified") && (otherMoney.currency != "unspecified") ){
        if ( otherMoney.currency != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
    if ( units != otherMoney.units || cents != otherMoney.cents ){
        return true;
    }
    else {
        return false;
    }
}

//------------------------------------

money&& money::operator + (const money& otherMoney){
    // If both objects have defined currency but they are not the same - do mtf error.
    if ( (currency != "unspecified") && (otherMoney.currency != "unspecified") ){
            if ( otherMoney.currency != currency ) {
                throw monetary_error{"Ej samma valutakod"};
            }
    }
    
    int unitSum;
    int centSum;
    unitSum= units + otherMoney.units;
    centSum = cents + otherMoney.cents;
    if (centSum >= 100 ){
        unitSum = unitSum + 1;
        centSum = centSum - 100;
    }
    
    if ( (currency == "unspecified") && (otherMoney.currency == "unspecified") ){
        return move(money("unspecified", unitSum, centSum));
    }
    else if (currency == "unspecified"){
        return move(money(otherMoney.currency, unitSum, centSum));
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
	
	return this;
}

//------------------------------------

money money::operator ++ (int separatemefrom){
	
    money temp(this);
	
	cents = cents + 1; 
	if ( cents >= 100 ){
		units = units + 1; 
		cents = cents - 100;
	}
	
	return temp;
	
}

//------------------------------------

string money::getCurrency() const{

}

//------------------------------------
