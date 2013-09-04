// labb1-1.cc

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

//---------------------------------
int get-roof (int roof){
	
	cout << "Please enter a integer larger than 0" << "\n";
	cin >> roof;
	
	while [ roof < 1 ]{
		cout << "Felaktigt värde, försök igen!" << "\n";
		cin >> roof;
	}
	
	return roof;
}

//---------------------------------

void print-value(string current-string){
	
	int diff = 10 - current-string.length();
	
	cout << setw(diff) << current-string;
}

//---------------------------------

string hex-make(int decimal){
	
	string hex;
	itoa(decimal,hex,16);
	
	return hex;
}

//---------------------------------

string okt-make(int decimal){
	
	string oktal;
	itoa(decimal,oktal,8);
	
	return oktal;
}


//---------------------------------

void print-list(int roof){
	
	int x = 1:
	
	cout << "       DEC       OKT       HEX" << "\n";
	for [ x <= roof ]{
		print-value(x);
		print-value(okt-make(x));
		print-value(hex-make(x));
		
		cout << "\n";
		
		x++;
	}

//---------------------------------

int main{
	
	int roof;
	
	roof = get-roof(roof);
	
	print-list(roof);
	
	return 0;
}
