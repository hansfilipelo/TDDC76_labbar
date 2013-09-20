#include <stdlib.h>
#include <iostream>
#include "./list.h"

using namespace std;

int main(){
	list testis;
	testis.insert("koolt");
	testis.insert("badger");
	testis.insert("erik");
	
	testis.print();
	
	cout << endl << "Reverse" << endl;
	testis.reverse();
	
	testis.print();
	
	cout << endl << "Reversse igen" << endl;
	testis.printReverse();

	testis.clear();
	cout << endl << "Rensat skit" << endl;
	testis.print();
	return 0;
}
