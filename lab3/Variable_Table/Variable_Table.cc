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
long double Variable_Table::get_value(string name) const{
    return varMap.at(name);
}

// -------------------------------------
// adderar en varibel till map:en
void Variable_Table::insert(string name, long double value) {
    
    if (find(name)) {
        throw logic_error{"Variabeln är redan definerad"};
    }
    
    varMap.insert(pair<string,long double>(name, value));
}

// -------------------------------------
// printar ut alla sparade variabler var = värde
void Variable_Table::list() const{
    for (auto it = varMap.cbegin(); it != varMap.cend(); ++it) {
        cout << it->first << " = " << it->second << endl;
    }
}

// -------------------------------------
// true om variabeln tidigare definierad
bool Variable_Table::find(string name) const {
    return varMap.count(name);
}

// -------------------------------------
// rensar mapen
void Variable_Table::clear() {
    varMap.clear();
}

// -------------------------------------
// Kontrollerar om tabell tom.

bool Variable_Table::empty() const {
    return varMap.empty();
}

// ------------------------------------
// Sets already existing variable

void Variable_Table::set_value(std::string name, long double inValue) {
    
    if (not(find(name))) {
        throw logic_error{"Variabeln finns ej"};
    }
    varMap.erase(name);
    varMap.insert(pair<string,long double>(name, inValue));
}




