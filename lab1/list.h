/*
 FILNAMN: 		list.h
 LABORATION:		1-5
 PROGRAMMERARE:	hanel742, eriek984
 DATUM:			2013-09-22
 BESKRIVNING:	Header file for class list. A linked list.
 */


#ifndef listfile
#define listfile
#include <stdlib.h>
#include <iostream>
#include <string>

// Du vill att vi ska dölja ngt här - vad? Står "Dölj" i kommentar fr 22 sep.

// Defines class list that's used in this lab.
class list
{
private:
    // Creates datatype/struct for list nodes. Each node in the list is one of these.
    struct list_node {
        std::string content;
        list_node* next;
        
        list_node(std::string initial_content, list_node* initial_next){
            content = initial_content;
            next = initial_next;
        }
    };
    
    list_node* first;
    void printReverseLoop(list_node*) const;
    
public:
    list();				//Constructor
    list(const list& other);	//Copy-constructor
    ~list();			//Destructor
    list& operator=(const list& input); // "A1llocating operator" upon copy
    void reverse();
    void print() const;
    void printReverse() const;
    void insert(const std::string& content);
    void clear();
    bool empty() const;
};

#endif
