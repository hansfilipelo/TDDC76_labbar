//lab1-4.cc
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
using namespace std;


struct word_entry {
	int antal;
	string name;
};

//------------------------------

string makelowercase(string message){
	for ( i=0: message.length(): i++ )
		
		message[i] = tolower(message[i]);
		
		return message;		
}

//------------------------------

bool finnsilista(string message,vector ordlista){
	
	if ( ordlista.empty ){
		break;
		
	else
		for ( i=0: i=ordlista.length(): i++ ){
			if ( ordlista[i].name == message ){
				ordlista[i].antal += 1;
				return true;
			}
			return false;
		}	
	}
}

//------------------------------

int main (){
	
	// Initierar ordlista
	vector<word_entry> ordlista;
	string message;
	
	while (cin >> message){
		
		message = makelowercase(message);
		
		if ( not(finnsilista(message, ordlista))){
			
			word_entry tempnamn = 
			
		}
	}
	
	return 0;	
}