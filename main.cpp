// unordered_multiset.cpp : définit le point d'entrée de l'application.
//

#include "unordered_multiset.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	unordered_multiset<int> m1;
	cout << m1 << endl;
	return 0;
}
