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
		list();
		~list();
		void reverse();
		void print();
		void print_reversed();
		void insert(string content);
		void clear();
	private:
		int length;
		list_node* first;
};