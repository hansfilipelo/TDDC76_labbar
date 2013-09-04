#include <iostream>
using namespace std;

int main(int argc, char* argv[]) 
{
	if (argc == 1){
		cout << "C++ is so cool!\n";
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		cout << argv[i] << "\n";
	}
}