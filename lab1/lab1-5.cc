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
	
	testis.reverse();
	
	testis.print();
	
	return 0;
}