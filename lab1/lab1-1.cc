// labb1-1.cc

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

/*---------------------------------
getRoof
Purpose: Gets a value from user to be used as top value (roof) for output.
*/
static int getRoof (int roof){
	
	cout << "Please enter a integer larger than 0" << "\n";
	cin >> roof;
	
	while (roof < 1 ){
		cout << "Felaktigt värde, försök igen!" << "\n";
		cin >> roof;
	}
	
	return roof;
}

/*---------------------------------
printDec
Purpose: Print value in base 10.
*/

static void printDec(int decimal){
	
	cout << setw(10) << dec << decimal;
}


/*---------------------------------
printOct
Purpose: Print value in base 8.
*/

static void printOct(int decimal){
	
	cout << setw(10) << oct << decimal;
}


/*---------------------------------
printHex
Purpose: Print value in base 16.
*/

static void printHex(int decimal){
	
	cout << setw(10) << hex << decimal;
}


/*---------------------------------
printList
Purpose: Correctly aligns output from functions above. 
*/

static void printList(int roof) {
	
	cout << "       DEC       OKT       HEX" << "\n";
	for ( int x = 1; x <= roof; x++){
		printDec(x);
		printOct(x);
		printHex(x);
		
		cout << "\n";
		
	}
}

//---------------------------------

int main() {
	
	int roof;
	
	roof = getRoof(roof);
	
	printList(roof);
	
	return 0;
}