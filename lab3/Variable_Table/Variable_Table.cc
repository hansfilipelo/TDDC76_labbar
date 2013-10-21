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
//tar in ett namn(variabel) och ger tillbaka värdet
long double Variable_Table::getVar(string name) const{
    return varMap.at(name);
}

// -------------------------------------
// adderar en varibel till mapen
void Variable_Table::addVar(string name, long double value) {
    varMap.insert(pair<string,long double>(name, value));
}

// -------------------------------------
// printar ut alla sparade variabler var = värde
void Variable_Table::print() const{
    for (auto it = varMap.cbegin(); it != varMap.cend(); ++it) {
        cout << it->first << " = " << it->second << endl;
    }
}

// -------------------------------------
// true om variabeln tidigare definierad
bool Variable_Table::exist(string name) const {
    return varMap.count(name);
}

// -------------------------------------
// rensar mapen
void Variable_Table::clear() {
    varMap.clear();
}