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


//definierar en ny klass variable table, egentligen bara ett abstraktionslager för map
class Variable_Table {

public:
    long double get_value(std::string name) const;
    void insert(std::string, long double);
    void set_value(std::string, long double);
    void list() const;
    bool find(std::string) const;
    void clear();
    bool empty()const;
    
protected:
    std::map<std::string,long double> varMap;
};

#endif
