/*
FILNAMN: 		Variable_Table.cc
LABORATION:		
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-10-18
BESKRIVNING:	
*/

#include "Variable_Table.h"

using namespace std;


// -------------------------------------

long double Variable_Table::getVar(string name) const{
    return varMap.at(name);
}

// -------------------------------------

void Variable_Table::addVar(string name, long double value) {
    varMap.insert(pair<string,long double>(name, value));
}

// -------------------------------------

void Variable_Table::print() const{
    for (auto it = varMap.cbegin(); it != varMap.cend(); ++it) {
        cout << it->first << " = " << it->second << endl;
    }
}

// -------------------------------------

bool Variable_Table::exist(string name) const {
    return varMap.count(name);
}

// -------------------------------------

void Variable_Table::clear() {
    varMap.clear();
}