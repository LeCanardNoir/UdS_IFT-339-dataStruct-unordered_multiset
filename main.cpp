// unordered_multiset.cpp : définit le point d'entrée de l'application.
//

#include "unordered_multiset.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	unordered_multiset<string> m1(10);
	m1.insert("test");
	m1.insert("test2");
	m1.insert("test3");
	cout << m1 << endl;
	return 0;
}
