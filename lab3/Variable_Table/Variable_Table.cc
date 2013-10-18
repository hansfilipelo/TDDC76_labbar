/*
FILNAMN: 		Variable_Table.cc
LABORATION:		
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-10-18
BESKRIVNING:	
*/

#include "Variable_Table.h"

using namespace std;

long double Variable_Table::getVar(string name) const{
    return varMap.at(name);
}

void Variable_Table::addVar(string name, long double value) {
    cout << name << endl;
    varMap.insert(pair<string,long double>(name, value));
//    varMap.at(name) = value;
    cout << varMap.at(name);
}