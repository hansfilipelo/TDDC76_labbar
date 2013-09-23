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
BESKRIVNING:	Laboration 1-5
*/

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
_EOF_