/*
FILNAMN: 		Variable_Table.h
LABORATION:		
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-10-17
BESKRIVNING:	
*/

#ifndef VAR_H
#define VAR_H
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
    long double getVar(std::string) const;
    void addVar(std::string, long double);

private:
    std::map<std::string,long double>     varTable;
};

#endif