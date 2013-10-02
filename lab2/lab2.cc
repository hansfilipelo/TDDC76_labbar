/*
FILNAMN: 		lab2.cc
LABORATION:		
PROGRAMMERARE:	hanel742, eriek984
DATUM:			2013-09-26
BESKRIVNING:	
*/

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "./Monetary.h"
using namespace std;
using namespace monetary;

int main(){
    
    money erik("PWN",100,00);
    money hf("USC",200,50);
    
    money odef(50,00);
    
    try {
        erik = erik + odef;
        
        cout << "Eriks pengar" << endl;
        cout << erik.getCurrency() << endl;
    } catch (const monetary_error& error) {
        cout << error.what() << endl;
    }
    
    try {
        cout << "Eriks och H-Fs pengar" << endl;
        erik = erik + hf;
    } catch (const monetary_error& error) {
        cout << error.what() << endl;
    }
    
    string teststring = "unspecified";
    
    if (teststring == "unspecified"){
        cout << "Ja det blir en sträng av skiten" << endl;
    }
    
    if ( odef.getCurrency() == "unspecified" ){
        cout << "odef och unspecified är lika"
    }
    
	return 0;
}
