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
	
	while [ roof < 1 ]{
		cout << "Felaktigt värde, försök igen!" << "\n";
		cin >> roof;
	}
	
	return roof;
}

//---------------------------------

void printValue(string currentString){
	
	int diff = 10 - currentString.length();
	
	cout << setw(diff) << currentString;
}

//---------------------------------

string hexMake(int decimal){
	
	string hex;
	itoa(decimal,hex,16);
	
	return hex;
}

//---------------------------------

string oktMake(int decimal){
	
	string oktal;
	itoa(decimal,oktal,8);
	
	return oktal;
}


//---------------------------------

void printList(int roof){
	
	int x = 1:
	
	cout << "       DEC       OKT       HEX" << "\n";
	for [ x <= roof ]{
		printValue(x);
		printValue(oktMake(x));
		printValue(hexMake(x));
		
		cout << "\n";
		
		x++;
	}

//---------------------------------

int main{
	
	int roof;
	
	roof = getRoof(roof);
	
	printList(roof);
	
	return 0;
}
