#!/bin/bash

FILE=$1
touch $FILE

cat << _EOF_ > ./$FILE
/*
_EOF_

echo "FILNAMN: 		$FILE" >> $FILE

cat << _EOF_ >> ./$FILE
LABORATION:		
PROGRAMMERARE:	hanel742, eriek984
_EOF_

echo "DATUM:			$(date '+%Y-%m-%d')" >> $FILE

cat << _EOF_ >> ./$FILE
BESKRIVNING:	
*/

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){
	
	return 0;
}
_EOF_

echo "Skapat ny $FILE"
