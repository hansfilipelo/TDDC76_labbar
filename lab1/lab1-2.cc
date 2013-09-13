// lab1-2.cc

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main () {
	
	double kelvin = 1; 
	
	//If Kelvin is'nt 0, continue
	while ( kelvin != 0) {
		cout << "Ge en temperatur i Kelvin:" << "\n";
		cin >> kelvin;
		
		if ( kelvin < 0 ) {
			cout << "Negativa kelvinvärden är ej tillåtna!" << "\n\n";
		}
		
		else {
			double celsius = kelvin - 273.15;
			double fahrenheit = 1.8*kelvin - 495.67;
			cout << kelvin << " Kelvin motsvarar " << celsius << " grader Celsius eller " << fahrenheit << " grader Fahrenheit." << "\n\n";
		}
	}
	
	cout << "Slut" << "\n";
	
	return 0;
}