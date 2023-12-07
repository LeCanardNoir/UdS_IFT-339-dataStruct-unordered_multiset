// unordered_multiset.cpp : définit le point d'entrée de l'application.
//

#include "unordered_multiset.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	unordered_multiset<string> m1;
	size_t i = 0;

	for (; i < 8; i++)
	{
		m1.insert("data(" + std::to_string(i) + ")");
	}

	cout << m1 << endl;

	m1.erase("data(7)");

	cout << m1 << endl;

	for (; i < 64; i++)
	{
		m1.insert("data(" + std::to_string(i) + ")");
	}

	m1.insert("data(29)");

	cout << m1 << endl;

	m1.erase("data(10)");
	m1.erase("data(10)");
	m1.erase("data(13)");
	m1.erase("data(29)");

	cout << m1 << endl;

	for(auto it = m1.begin(); it != m1.end(); ++it)
		cout << *it + ", ";


	cout << endl;
	cout << endl;

	for (auto it_back = --m1.end(); it_back != m1.begin(); --it_back)
		cout << *it_back + ", ";

	return 0;
}
