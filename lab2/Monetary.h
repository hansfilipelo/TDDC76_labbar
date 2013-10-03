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
        money(const std::string currCode, const int unitValue, const int centValue);
        money(const int unitValue, const int centValue);
        money(const money& otherMoney);
        
        //Operators
        money& operator = (const money& otherMoney);
        bool operator < (const money& otherMoney);
        bool operator > (const money& otherMoney);
        bool operator != (const money& otherMoney);
        bool operator == (const money& otherMoney);
        money&& operator + (const money& otherMoney);
	money&& operator - (const money& otherMoney);
        money& operator ++ ();						// ++m3
        money operator ++ (int);	// m3++
	bool operator <= (const money& otherMoney);
	bool operator >= (const money& otherMoney);
	money& operator += (const money& otherMoney);
	money& operator -= (const money& otherMoney);
	money& operator -- ();						// --m3
        money operator -- (int);	// m3--
        
	friend std::istream& operator >> (std::istream& input, money& otherMoney);
        friend std::ostream& operator << (std::ostream& stream, const money& outsideMoney);
        
        // Functions for accessing data
        std::string getCurrency() const;
        int getUnits() const;
        int getCents() const;
	void setCurrency(string currCode);
	void setUnits(int unitValue);
	void setCents(int centValue);
        void print(ostream& output) const;
        
    private:
        std::string currency;
	// No we don't want these stuff below unsigned
        int units;
        int cents;
	void currencyCheck (const money& otherMoney);
	};
}

#endif