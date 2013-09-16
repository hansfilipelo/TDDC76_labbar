//lab1-4.cc
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct word_entry {
	int antal;
	string name;
};

//------------------------------

static string makelowercase(string message){
	transform(message.begin(), message.end(),message.begin(),::tolower);
	return message;
}

//------------------------------

static bool finnsilista(string message,vector<word_entry>& ordlista){
	
	if ( ordlista.empty() ){
		return false;
		}
		
	else {
		for (unsigned int i=0; i < ordlista.size(); i++ ){
			if ( ordlista[i].name == message ){
				ordlista[i].antal += 1;
				return true;
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
	
	if ( ordlista.size() > 0 ){
		for(unsigned int i=0; i < ordlista.size(); i++){
			if(ordlista[i].name > temp.name){
				ordlista.insert(ordlista.begin() + i, temp);	
				break;
			}
			else if (ordlista.size() == (i + 1)) {
				ordlista.push_back(temp);
			}
		}
	}
	else {
		ordlista.push_back(temp);
	}
}
		
//------------------------------

static void printshit(vector<word_entry>& ordlista){
	for (unsigned int i=0; i < ordlista.size(); i++){
		cout << setw(10) << ordlista[i].name << setw(10) << ordlista[i].antal << endl;
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
			addlistsort(message, ordlista);
		}
	}
	
	printshit(ordlista);
	return 0;	
}