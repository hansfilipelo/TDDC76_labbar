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

void list::reverse(){
	
	list_node* reverseLooper(list_node* current){
		if (current->next == nullptr){
			first = current;
			return current;
		}
		else {
			reverseLooper(current)->next = current;
		}	
	};
	
	list_node* temp = first;
	reverseLooper(temp)->next = nullptr;
}

void list::printreversed(){

	void printreversedloop(list_node* current){
		if(current->next == nullptr){
			cout<<current->content<<endl;
			}
		else{
			printreversedloop(current->next)
			cout<<current->content<<endl;
			}
		}
	prinreversedloop(first);
}