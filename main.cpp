// unordered_multiset.cpp : définit le point d'entrée de l'application.
//

#include "unordered_multiset.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	unordered_multiset<string> m1;
	
	for (size_t i = 0; i < 100; i++)
	{
		m1.insert("data(" + std::to_string(i) + ")");
	}

	m1.erase("data(7)");

	cout << m1 << endl;

	return 0;
}
