/*
FILNAMN: 		Lab1-4.cc
LABORATION:		1-4
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-09-23
BESKRIVNING:	Laboration 1-4. Takes user input and puts in vector alphabeticaly. 
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

//------------------------------
// Struct for word-entries in vector.
struct word_entry {
	int antal;
	string name;
};

//------------------------------
//Converts input to lowercase
static string makeLowerCase(string message){
	transform(message.begin(), message.end(),message.begin(),::tolower);
	return message;
}

//------------------------------
//Checks to see a given word already is in list
static bool inList(string message,vector<word_entry>& wordlist){
	
	if ( wordlist.empty() ){
		return false;
		}
		
	else {
		for (unsigned int i=0; i < wordlist.size(); i++ ){
			//If in list - add upon count of times word's been "mentioned". 
			if ( wordlist[i].name == message ){
				wordlist[i].antal += 1;
				return true;
			}
		}
	}
	return false;
}

//------------------------------
//Adds item to list - sorted. 

static void addListSort(string& message, vector<word_entry>& wordlist){
	
	word_entry temp;
	temp.name = message;
	temp.antal = 1;
	unsigned long length = wordlist.size();
	
	if ( length > 0 ){
		for(unsigned int i=0; i < length; i++){
			if(wordlist[i].name > temp.name){
				wordlist.insert(wordlist.begin() + i, temp);
				break;
			}
			else if (length == (i + 1)) {
				wordlist.push_back(temp);
			}
		}
	}
	else {
		wordlist.push_back(temp);
	}
}
		
//------------------------------
//Prints wordlist
static void printShit(vector<word_entry>& wordlist){
	for (unsigned int i=0; i < wordlist.size(); i++){
		cout << setw(10) << wordlist[i].name << setw(10) << wordlist[i].antal << endl;
	}
}
//------------------------------

int main (){
	
	// Initiates wordlist
	vector<word_entry> wordlist;
	string message;
	
	while (cin >> message){
		
		message = makeLowerCase(message);
		
		if ( not(inList(message, wordlist))){
			addListSort(message, wordlist);
		}
	}
	
	printShit(wordlist);
	return 0;	
}
