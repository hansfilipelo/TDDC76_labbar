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

list_node* reverseLoop(list_node* current){
	if (current->next == nullptr){
		first = current;
		return current;
	}
	else {
		reverseLoop(current)->next = current;
		return nullptr;
	}
}

void list::reverse(){
	list_node* temp = first;
	reverseLoop(temp)->next = nullptr;
}

//------------------------------------

void printReversedLoop(list_node* current){
	if(current->next == nullptr){
		cout<<current->content<<endl;
	}
	else{
		printReversedLoop(current->next);
		cout<<current->content<<endl;
	}
}

void list::printReversed(){
	
	printReversedLoop(first);
}
