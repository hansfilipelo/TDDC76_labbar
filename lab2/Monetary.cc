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

money::money(){
	currency = "unspecified";
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
    if ( (currency != "unspecified") && (otherMoney.getCurrency() != "unspecified") ){
        if ( otherMoney.getCurrency() != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
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
    
    
    cout << "slutet av =" << endl;
    
	return *this;
}

//------------------------------------

bool money::operator < (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
    if ( (currency != "unspecified") && (otherMoney.getCurrency() != "unspecified") ){
        if ( otherMoney.getCurrency() != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
    
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
    if ( (currency != "unspecified") && (otherMoney.getCurrency() != "unspecified") ){
        if ( otherMoney.getCurrency() != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
    
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
    if ( (currency != "unspecified") && (otherMoney.getCurrency() != "unspecified") ){
        if ( otherMoney.getCurrency() != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
    if ( units == otherMoney.getUnits() && cents == otherMoney.getCents() ){
        return true;
    }
    else {
        return false;
    }
}

//------------------------------------

bool money::operator != (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
    if ( (currency != "unspecified") && (otherMoney.getCurrency() != "unspecified") ){
        if ( otherMoney.getCurrency() != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
    if ( units != otherMoney.getUnits() || cents != otherMoney.getCents() ){
        return true;
    }
    else {
        return false;
    }
}

//------------------------------------

money&& money::operator + (const money& otherMoney){
    
    // If both objects have defined currency but they are not the same - do mtf error.
    if ( (currency != "unspecified") && (otherMoney.getCurrency() != "unspecified") ){
        if ( otherMoney.getCurrency() != currency ) {
            throw monetary_error{"Ej samma valutakod"};
        }
    }
    
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
    
    cout << "slutet av +" << endl;
    
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

string money::getCurrency() const{
    
    return currency;
}

//------------------------------------

unsigned int money::getUnits() const{
    return units;
}

//------------------------------------

unsigned int money::getCents() const{
    return cents;
}

//------------------------------------

//void operator >> (const string input){
//    if ( input.peak() )
//}

//------------------------------------

ostream& operator << (ostream& stream, const money& outsideMoney){
    
    if(outsideMoney.getCurrency() == "unspecified"){
		return stream << outsideMoney.getUnits() << "." << outsideMoney.getCents();
    }
    return stream << outsideMoney.getCurrency() << " " << outsideMoney.getUnits() << "." << outsideMoney.getCents();
}

//------------------------------------

void money::print(ostream& output){
    output << *this;
}




