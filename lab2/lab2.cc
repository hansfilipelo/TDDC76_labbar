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
    
    money odef(50,99);
    
    try {
        erik = erik + odef;
        
        cout << "Eriks pengar" << endl;
        cout << erik.getUnits() << endl;
    } catch (const monetary_error& error) {
        cout << error.what() << endl;
    }
    
    try {
        cout << "Eriks och H-Fs pengar" << endl;
        erik = erik + hf;
    } catch (const monetary_error& error) {
        cout << error.what() << endl;
    }
    
    try {
        erik > odef;
        cout << "Erik är större än odef" << endl;
    } catch (const monetary_error& error) {
        cout << error.what() << endl;
    }
    
    try {
        erik < hf;
    } catch (const monetary_error& error) {
        cout << error.what() << endl;
    }
    
    try {
	    cout << erik << endl;
    } catch (const monetary_error& error) {
	    cout << error.what() << endl;
    }
    
    try {
	    cout << ++erik << endl;
	    cout << --erik << endl;
	    cout << (erik += odef) << endl;
    } catch (const monetary_error& error) {
	    cout << error.what() << endl;
    }
    
    try {
		cin >> erik;
        cin >> odef;
		cout << erik << endl;
        cout << odef << endl;
    } catch (const monetary_error& error) {
	    cout << error.what() << endl;
    }
    
    return 0;
}