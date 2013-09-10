//lab1-3.cc
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

int main()
{
int alfa;
int siffror;
int interp;
int vita;
int tot;
char tecken;

while (cin>>tecken)
{
tot = tot + 1;
if (isdigit(tecken))
siffror = siffror + 1;
if (isalpha(tecken))
alfa = alfa + 1;
if (ispunct(tecken))
interp = interp + 1;
if (isspace(tecken))
vita =vita + 1;
}
cout<<"\n"<<"Indata innehöll:"<<"\n" << siffror << " siffror"<<"\n";
cout<<  alfa << " alfabetiska tecken"<<"\n";
cout<< interp << " interpunktionstecken"<<"\n";
cout<< vita << " vita tecken"<<"\n";
cout<< tot << " tecken totalt"<<"\n";
return 0;
}

