/*
FILNAMN: 		Lab1-5.cc
LABORATION:		1-5
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-09-22
BESKRIVNING:	Runs test on class "list" implemented in list.h and list.cc. 
*/

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "./list.h"

using namespace std;
//main function is called with arguments in terminal ./lab1-5 "pathname" 
int main(int argc, char* argv[]){
	
	// Defines a list
	list testis;
	
	//If there isn't ONE argument, exit. 
	if ( (argc > 2) ){
		cout << setw(10) << "Please enter a valid filename" << endl;
	}
	else if ( argc == 0 ){
		cout << setw(10) << "Please enter a valid filename" << endl;
	}
	
	//Else enter contents of file into list
	else{
		//first (0) argument is the list
		//Open inputfile. While-loop gets stuff into list. 
		//You (Jonas) gave us a comment here - stating that argv[1] is second argument - and yes it is.. 
		// argv[1] is the "file call" (i e ./lab1-5). We will not change the lines below. 
		ifstream inputfile;
		inputfile.open(argv[1], ifstream::in);
		
		if( inputfile.is_open() ){
			string line;
			while ( getline (inputfile, line) ){
      				testis.insert(line);
      		}
		inputfile.close();
      	}
		
		//If file doesn't exists. 
      	else{
      		cout << "Please enter path to a valid file" << endl;
      	}
}

	//test rutine
	testis.print();
	cout << endl;
	
	cout << endl << "Reversing list and printing" << endl;
	testis.reverse();
	testis.print();
	cout << endl;
	
	cout << endl << "Reversed list printed reversed, double minus equals plus." << endl;
	testis.printReverse();
	cout << endl;

	list testis2(testis);
	cout << "testis2 print" << endl;
	testis2.print();
	cout << endl;

	testis.clear();
	cout << endl << "Testing clear function" << endl;
	testis.print();
	cout << endl;
	
	return 0;
}
