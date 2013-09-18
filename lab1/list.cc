//file list.cc
#include <stdlib.h>
#include <iostream>
#include <string>
#include "list.h"

using namespace std;

list::list(int argc, string* argv[]){
	if (argc =! 1){
		cout << "setw(10) << "Please enter a valid filename" << endl;
	}
	else{
		ifstream inputfile (argv[0]);
		if(inputfile.is_open){
			while ( getline (inputfile,line) )
				{
      				pushback(line);
      			}
      		}
      	else{
      		cout << "Please enter path to a valid file" << endl;
      	} 
	}
}

list::getStruct(int pos){
	if (pos == 0){
		return first;
	}
	else {
		temp& = first.next;
		for ( i=0 ; i < pos && i < length ; i++ ){
			temp& = temp.next;
			if ( i == (pos -1)){
				return temp&;
			}
		}
	}
}
			
list::pushback(string content){
	