/*
 FILNAMN: 		Variable_Table.h
 LABORATION:
 PROGRAMMERARE:	hanel742, eriek984
 DATUM:			2013-10-18
 BESKRIVNING:
 */

#ifndef VART_H
#define VART_H
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>

class Variable_Table {
    
public:
    long double getVar(std::string name) const;
    void addVar(std::string, long double);
    
protected:
    std::map<std::string,long double> varMap;
};

#endif