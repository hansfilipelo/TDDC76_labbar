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

// Creates datatype/struct for list nodes. Each node in the list is one of these. 
struct list_node {
	string content;
	list_node* next;
	
	list_node(std::string initial_content, list_node* initial_next){
		content = initial_content;
		next = initial_next;
	}
};

// Defines class list that's used in this lab.
class list
{
	public:
		list();				//Constructor
		list(const list& other);	//Copy-constructor
		~list();			//Destructor
		void reverse();
		void const print();
		void const printReverse();
		void insert(const std::string content);
		void clear();
		bool const empty();
	private:
		list_node* first;
};

#endif
