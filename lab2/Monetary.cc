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
		//Här fukking error
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

money::money(const std::string currCode){
	if ( currCode.length() != 3 ){
		//Här fukking error
	}
	
	currency = currCode;
	units = 0;
	cents = 0;
}


//------------------------------------

money& money::operator = (const money& otherMoney){
	
	currency = otherMoney.currency;
	units = otherMoney.units;
	cents = otherMoney.cents;
	
	return *this;
}

//------------------------------------

bool money::operator < (const money& otherMoney){

}

//------------------------------------

bool money::operator > (const money& otherMoney){

}

//------------------------------------

bool money::operator == (const money& otherMoney){

}

//------------------------------------

bool money::operator != (const money& otherMoney){

}

//------------------------------------

money& money::operator + (const money& otherMoney){

}

//------------------------------------

money& money::operator ++ (){

}						// ++m3

//------------------------------------

money money::operator ++ (int separatemefrom){

}	// m3++

//------------------------------------

string money::getCurrency() const{

}

//------------------------------------
