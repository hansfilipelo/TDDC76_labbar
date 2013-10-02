/*
 FILNAMN: 		Monetary.h
 LABORATION:
 PROGRAMMERARE:	hanel742, eriek984
 DATUM:			2013-09-26
 BESKRIVNING:
 */


#ifndef monetaryfile
#define monetaryfile
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "./monetary_error.cc"

namespace monetary{
	class money{
        
    public:
        money();
        money(const std::string currCode);
        money(const std::string currCode, const unsigned unitValue, const unsigned centValue);
        money(const unsigned unitValue, const unsigned centValue);
        money(const money& otherMoney);
        
        //Operators
        money& operator = (const money& otherMoney);
        bool operator < (const money& otherMoney);
        bool operator > (const money& otherMoney);
        bool operator != (const money& otherMoney);
        bool operator == (const money& otherMoney);
        money&& operator + (const money& otherMoney);
        money& operator ++ ();						// ++m3
        money operator ++ (int);	// m3++
        
        // Functions for accessing data
        std::string getCurrency() const;
        int getUnits() const;
        int getCents() const;
        
    private:
        std::string currency;
        unsigned units;
        unsigned cents;
	};
}

#endif