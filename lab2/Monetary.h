/*
FILNAMN: 		Monetary.h
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

namespace monetary{
	class money{

		public:
			money();
			money(const std::string currCode);
			money(const std::string currCode, const unsigned unitValue, const unsigned centValue);
			money(const unsigned unitValue, const unsigned centValue);
	
			//Operators
			money& operator = (const money& otherMoney);
			bool operator < (const money& otherMoney);
			bool operator > (const money& otherMoney);
			bool operator != (const money& otherMoney);
			bool operator == (const money& otherMoney);
			money& operator + (const money& otherMoney);
			money& operator ++ ();						// ++m3
			money operator ++ (int separatemefrom);	// m3++
	
			//Functions
			std::string getCurrency() const;

		private:
			std::string currency;
			unsigned units;
			unsigned cents;
	};
}

