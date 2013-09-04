#include <iostream>
#include <string>
using namespace std;

const string message{"C++ is so cool!"};

int main()
{
	string first_name;

	cout << "Skriv ditt förnamn: ";
	cin >> first_name;

	cout << "\n" << first_name << " tycker \"" << message << "\"\n\n";

	return 0;
}