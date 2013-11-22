/*
 * kalkylator.cc
 *
 * Ett objekt av typen Calculator skapas i main() och Calculator::run()
 * kors. Om ett undantag kastas av Calculator::run() f�ngas detta och 
 * programmet avslutas sedan efter att ett felmeddelande skrivits ut.
 * Alla f�rutsedda fel ska ha f�ngats och hanterats av Calculator::run().
 */
#include "Calculator.h"
#include <iostream>
using namespace std;

int main()
{
   Calculator calc;

   try
   {
      calc.run();
   }
   catch (...)
   {
      cout << "Ett okant fel har intraffat.\n";
   }

   return 0;
}
