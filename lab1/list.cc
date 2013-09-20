//file list.cc
#include <stdlib.h>
#include <iostream>
#include <string>
#include "./list.h"

using namespace std;

list::list(){
	first = nullptr;
}

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
