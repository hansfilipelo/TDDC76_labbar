#!/usr/bin/bash

FILE="$1"

touch $FILE

echo "/*" >> $FILE
echo "FILNAMN: 		Lab1-5.cc" >> $FILE
echo "LABORATION:		1-5" >> $FILE
echo "PROGRAMMERARE:	hanel742, eriek984" >> $FILE
echo "DATUM:			$(date '+%Y-%m-%d')" >> $FILE
echo "BESKRIVNING:	Laboration 1-5" >> $FILE
echo "*/" >> $FILE