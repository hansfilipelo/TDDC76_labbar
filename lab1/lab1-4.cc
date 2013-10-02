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
//Adds item to list - sorted. 

static void addListSort(const string& message, vector<word_entry>& wordlist){
	
    // Pre-define length in order for it to be constant.
    const unsigned long length = wordlist.size();
    
    //If list is longer than 0
    if ( length > 0 ){
		for(unsigned int i=0; i < length; i++){
            //If word exists - up count on word_entry
            if ( wordlist.at(i).name == message) {
                wordlist.at(i).antal += 1;
                break;
            }
            // If word doesn't exist - insert it
            else if (wordlist[i].name > message){
                word_entry temp;
                temp.name = message;
                temp.antal = 1;
                
                wordlist.insert(wordlist.begin() + i, temp);
                break;
            }
            
            else if (length == (i + 1)) {
                word_entry temp;
                temp.name = message;
                temp.antal = 1;
                
                wordlist.push_back(temp);
            }
        }
    }
    else {
        word_entry temp;
		temp.name = message;
		temp.antal = 1;
        
        wordlist.push_back(temp);
    }
}
		
//------------------------------
//Prints wordlist
static void print(const vector<word_entry>& wordlist){
	// Formatting
	cout << setw(10) << "WORD" << setw(10) << "TIMES" << endl;
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
		
		addListSort(message, wordlist);
	}
	
	print(wordlist);
	return 0;
}