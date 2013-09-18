//file list.h
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

struct list_node {
	string content;
	struct<list_node> * next;
};
//Does struct<list-node> point to null at init?
	

class list
{
	public:
		list(int argc, string* argv[]);
		~list();
		void reverse();
		void print();
		void print_reversed();
		string select(int pos);
		void insert(string content,int pos);
		void push_back(string content);
		void delete(pos);		
	private:   
		int length;
		struct<list_node> * first;
};