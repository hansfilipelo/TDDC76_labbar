//file list.cc
#include <stdlib.h>
#include <iostream>
#include <string>
#include "./list.h"





using namespace std;

list::list(){
	first = nullptr;
}

//------------------------------------

list::list(const list& other){
	
	first = nullptr;
	
	cerr << "Innan if" << endl;
	if (other.first == nullptr){
	}
	else{
		cerr << "innan list_node" << endl;
		list_node* current = other.first;
		
		cerr << "innan while" << endl;
		while (current != nullptr){
			insert(current->content);
			current = current->next;
		}
		
		reverse();
	}
}


//------------------------------------

list::~list(){
	this->clear();

}

//------------------------------------

void list::clear(){
	list_node* current = first->next;
	list_node* next;
	first = nullptr; 

	while ( current->next != nullptr ){
		next = current->next;
		delete current;
		current = next;
	}
	
	delete current;
	delete next;
}

//------------------------------------
void list::insert(string content){
	first = new list_node(content,first);
}

void list::print(){
	if (first == nullptr){
		cout << "List is empty" << endl;
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

void printReverseLoop(list_node* current){
	if(current->next == nullptr){
		cout<<current->content<<endl;
	}
	else{
		printReverseLoop(current->next);
		cout<<current->content<<endl;
	}
}

void list::printReverse(){
	
	printReverseLoop(first);
}
