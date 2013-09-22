#!/usr/bin/bash

touch $1

echo "/*" >> $1
echo "FILNAMN: 		Lab1-5.cc" >> $1
echo "LABORATION:		1-5" >> $1
echo "PROGRAMMERARE:	hanel742, eriek984" >> $1
echo "DATUM:			$(date '+%Y-%m-%d')" >> $1
echo "BESKRIVNING:	Laboration 1-5" >> $1
echo "*/" >> $1
echo "" >> $1
echo "#include <stdlib.h>" >> $1
echo "#include <iostream>" >> $1
echo "#include <iomanip>" >> $1
echo "#include <fstream>" >> $1
echo "" >> $1
echo "using namespace std;" >> $1