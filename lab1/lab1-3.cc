//lab1-3.cc
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

int main()
{
// Initiating variables for later use


	int alfa;
	int siffror;
	int interp;
	int vita;
	int tot;
	char tecken;


/* This while loop prompts the user for inputs and 
evaluates for each character until an eof is received.
Increases the corresponding variable by one depending on the characters type 
*/



	while (cin>> noskipws>>tecken){
		tot += 1;
		if (isdigit(tecken))
			siffror += 1;
		if (isalpha(tecken))
			alfa += 1;
		if (ispunct(tecken))
			interp += 1;
		if (isspace(tecken))
			vita += 1;
	}

//Displays the result of the while-loop

	cout<<"\n"<<"Indata innehöll:"<<"\n" << siffror << " siffror"<<"\n";
	cout<<  alfa << " alfabetiska tecken"<<"\n";
	cout<< interp << " interpunktionstecken"<<"\n";
	cout<< vita << " vita tecken"<<"\n";
	cout<< tot << " tecken totalt"<<"\n";
	return 0;
}

