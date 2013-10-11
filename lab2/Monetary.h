/*
 FILNAMN: 		Monetary.h
 LABORATION:	2
 PROGRAMMERARE:	hanel742, eriek984
 DATUM:			2013-09-26
 BESKRIVNING:	List file for class money
 */


#ifndef monetaryfile
#define monetaryfile
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "./monetary_error.cc"
#include <stdexcept>

class monetary_error : public std::logic_error
{
public:
    explicit monetary_error(const string& what_arg) noexcept
    : std::logic_error{what_arg} {}
    
    explicit monetary_error(const char* what_arg) noexcept
    : std::logic_error{what_arg} {}
};




namespace monetary{
	class money{
        
    public:
        money(const std::string currCode = "unspecified", const int unitValue = 0, const int centValue = 0);
        money(const money& otherMoney);
        
        //Operators
        money& operator = (const money& otherMoney);
        bool operator < (const money& otherMoney) const;
        bool operator > (const money& otherMoney) const;
        bool operator != (const money& otherMoney) const;
        bool operator == (const money& otherMoney) const;
        money operator + (const money& otherMoney);
        money operator - (const money& otherMoney);
        money& operator ++ ();						// ++m3
        money operator ++ (int);	// m3++
        bool operator <= (const money& otherMoney) const;
        bool operator >= (const money& otherMoney) const;
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
        void print(ostream& output) const;
        
    protected:
        // Functions for setting data
        void setCurrency(const string& currCode);
        void setUnits(const int& unitValue);
        void setCents(const int& centValue);
        
    private:
        std::string currency;
		// No we don't want these stuff below unsigned :)
        int units;
        int cents;
        void currencyCheck (const money& otherMoney);
	};
}

#endif