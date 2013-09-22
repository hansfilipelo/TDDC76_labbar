/*
FILNAMN: 		Lab1-5.cc
LABORATION:		1-5
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-09-22
BESKRIVNING:	Laboration 1-5
*/

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "./list.h"

using namespace std;
//main function is called with arguments in terminal ./lab1-5 "pathname" 
int main(int argc, char* argv[]){

	list testis;

	if ( (argc =! 1) ){
		cout << setw(10) << "Please enter a valid filename" << endl;
	}
	else{
		//first (0) argument is the executable file eg lab1-5.cc
		ifstream inputfile;
		inputfile.open(argv[1], ifstream::in);
		
		if( inputfile.is_open() ){
			
			while ( getline (inputfile, string line) ){
      				testis.insert(line);
      		}
		inputfile.close();
      	}
		
      	else{
      		cout << "Please enter path to a valid file" << endl;
      	}
	}
	string message;
	cout<<"input file path please"<<endl;

	//test rutine
	testis.print();
	
	cout << endl << "Reversing list and printing" << endl;
	testis.reverse();
	
	testis.print();
	
	cout << endl << "Reversed list printed reversed" << endl;
	testis.printReverse();

	list testis2(testis);
	cout << "testis2 print" << endl;
	testis2.print();

	testis.clear();
	cout << endl << "Testing clear function" << endl;
	testis.print();
	
	return 0;
}
