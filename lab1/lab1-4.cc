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

static string makelowercase(string message){
	for (int i = 0; message.size(); i++ ){
		
		message[i] = tolower(message[i]);	
	}
	return message;
}

//------------------------------

static bool finnsilista(string message,vector<word_entry>& ordlista){
	
	if ( ordlista.empty() ){
		return false;
		}
		
	else {
		for (int i=0; i == ordlista.size(); i++ ){
			if ( ordlista[i].name == message ){
				ordlista[i].antal += 1;
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

//------------------------------

static void addlistsort(string& message, vector<word_entry>& ordlista){
	
	word_entry temp;
	temp.name = message;
	temp.antal = 1;
	
	for(int i=0; i < ordlista.size(); i++){
		if(ordlista[i].name > temp.name){
			ordlista.insert(ordlista.begin() + i, temp);	
			break;
		}
		else if (ordlista.size() == (i + 1)) {
			ordlista.push_back(temp);
		}
	}
}
		
//------------------------------

static void print-shit(vector<word_entry>& ordlista){
	for (int i=0; i < ordlista.size; i++){
		cout << ordlista[i].name << setw(10) << ordlista[i].antal << "/n";
	}
}
//------------------------------

static int main (){
	
	// Initierar ordlista
	vector<word_entry> ordlista;
	string message;
	
	while (cin >> message){
		
		message = makelowercase(message);
		
		if ( not(finnsilista(message, ordlista))){
			addlistsort(message, ordlista);
		}
	}
	
	print-shit(ordlista);
	return 0;	
}