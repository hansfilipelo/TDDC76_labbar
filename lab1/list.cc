/*
 FILNAMN: 		list.cc
 LABORATION:		1-5
 PROGRAMMERARE:	hanel742, eriek984
 DATUM:			2013-09-22
 BESKRIVNING:	Implementation file for classs list.
 */

//file list.cc
#include <stdlib.h>
#include <iostream>
#include <string>
#include "./list.h"

using namespace std;

/*Constructor: Sets pointer to nullptr*/
list::list(){
	first = nullptr;
}

//------------------------------------
/* Copyconstructor (constructor called with arguments):
 Makes called list a copy of the list given as argument*/
list::list(const list& other){
	
	first = nullptr;
	
	if (other.first == nullptr){
	}
	else{
		list_node* current = other.first;
		
		while (current != nullptr){
			insert(current->content);
			current = current->next;
		}
		
		reverse();
	}
}

//------------------------------------
// "A1llocating operator" upon copy
list& list::operator=(const list& input){
	
	if ( first == input.first ){
		return *this;
	}
	
	this->clear();
	list_node* current = input.first;
	
	while ( current != nullptr ){
		insert(current->content);
		current = current->next;
	}
	
    reverse();
    
	return *this;
}

//------------------------------------
/* Deconstructor:Calls the clear function for safe deconstruction*/
list::~list(){
	this->clear();
    
}

//------------------------------------
/*Deletes all list_nodes of target list to free up memory*/
void list::clear(){
    
	if (first == nullptr){
		return;
	}
    
	list_node* current = first->next;
	list_node* next;
	first = nullptr;
    
	while ( current->next != nullptr ){
		next = current->next;
		delete current;
		current = next;
	}
	
	delete current;
}

//------------------------------------
/* Adds new list_node with given content first in list */
void list::insert(const string& content){
	first = new list_node(content,first);
}


//------------------------------------
/*Prints content of all list_nodes in target list, if list is empty
 a message is saying just that is printed instead*/
void list::print() const{
	if (first == nullptr){
		cout << "List is empty" << endl;
		return;
	}
	else {
		cout << first->content << endl;
		list_node* temp = first->next;
		
		while (temp != nullptr){
			cout << temp->content << endl;
			temp = temp->next;
		}
	}
}

//------------------------------------
/*Flips the order of the list by rearranging pointers*/
void list::reverse(){
	list_node* current_temp = first;
	list_node* result_temp = nullptr;
	
	while(current_temp != nullptr){
		list_node* next_temp = current_temp->next;
		current_temp->next = result_temp;
		result_temp = current_temp;
		current_temp = next_temp;
	}
	
	first = result_temp;
	return;
}
//------------------------------------
/*Prints target list in reverse order, last to first*/
void printReverseLoop(list_node* current){
	if(current->next == nullptr){
		cout<<current->content<<endl;
	}
	else{
		printReverseLoop(current->next);
		cout<<current->content<<endl;
	}
}


//------------------------------------
/*Calls the helper function*/
void list::printReverse() const{
	if ( first != nullptr ){
		printReverseLoop(first);
	}
}

//------------------------------------
/*Checks to see if list is empty*/

bool list::empty() const{
	bool truth = false;
	
	if ( first == nullptr ){
		truth = true;
	}
	
	return truth;
}