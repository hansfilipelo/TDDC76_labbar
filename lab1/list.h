//file list.h
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

struct list_node {
	string content;
	list_node* next;
	
	list_node(string initial_content, list_node* initial_next){
		content = initial_content;
		next = initial_next;
		}
};
//Does struct<list-node> point to null at init?


class list
{
	public:
		list();				//Constructor
		list(const list& other);	//Copy-constructor
		~list();			//Destructor
		void reverse();
		void print();
		void printReverse();
		void insert(string content);
		void clear();
	private:
		list_node* first;
};
