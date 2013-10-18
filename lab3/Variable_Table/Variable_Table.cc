/*
FILNAMN: 		Variable_Table.cc
LABORATION:		
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-10-18
BESKRIVNING:	
*/

#include "Variable_Table.h"
#include <string>
using namespace std;

long double Variable_Table::getVar(string name) const{
    return varMap.find(name)->second;
}

void Variable_Table::addVar(string name, long double value) {
    varMap.insert(std::pair<string,long double>(name,value));
}