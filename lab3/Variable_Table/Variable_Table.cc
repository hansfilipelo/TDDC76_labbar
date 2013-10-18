/*
FILNAMN: 		Variable_Table.cc
LABORATION:		
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-10-17
BESKRIVNING:	
*/

#include "../Variable_Table/Variable_Table.h"
using namespace std;


// ----------------------------------
long double Variable_Table::getVar(string name){
    try {
        return varTable.at(varTable.find(name));
    } catch (std::out_of_range) {
        throw expression_error{"Variabeln är ej definerad"}
    }
}

// ----------------------------------

void Variable_Table::addVar(string name, Exppression_Tree* value){
    varTable.insert( std::pair<string,Expression_Tree*>(name,value) );
}

// ----------------------------------