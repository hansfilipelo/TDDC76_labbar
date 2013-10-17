/*
FILNAMN: 		Variable_Table.h
LABORATION:		
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-10-17
BESKRIVNING:	
*/

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include "../Expression/Expression.h"
#include "../Expression/Expression_Tree.h"

class Variable_Table {
public:
    class Expression_Tree* getVar(std::string) const;
    void addVar(std::string, Expression_Tree*);
private:
    std::map<std::string,Expression_Tree*>     varTable;
};