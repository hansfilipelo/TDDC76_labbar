// labb1-1.cc

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

//---------------------------------
int getRoof (int roof){
	
	cout << "Please enter a integer larger than 0" << "\n";
	cin >> roof;
	
	while (roof < 1 ){
		cout << "Felaktigt värde, försök igen!" << "\n";
		cin >> roof;
	}
	
	return roof;
}

//---------------------------------

void printDec(int decimal){
	
	cout << setw(10) << dec << decimal;
}

//---------------------------------

void printOct(int decimal){
	
	cout << setw(10) << oct << decimal;
}

//---------------------------------

void printHex(int decimal){
	
	cout << setw(10) << hex << decimal;
}

//---------------------------------

void printList(int roof) {
	
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