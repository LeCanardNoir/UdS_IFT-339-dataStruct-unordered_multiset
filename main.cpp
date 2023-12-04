// unordered_multiset.cpp : définit le point d'entrée de l'application.
//

#include "unordered_multiset.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	unordered_multiset<string> m1;
	m1.insert("zero");
	m1.insert("un");
	m1.insert("deux");
	m1.insert("trois");
	m1.insert("quatre");
	m1.insert("cinq");
	m1.insert("six");
	m1.insert("sept");
	m1.insert("huit");
	m1.insert("neuf");
	m1.insert("dix");
	m1.insert("onze");
	m1.insert("douze");
	m1.insert("treize");
	m1.insert("quatorze");
	m1.insert("quinze");
	m1.insert("seize");
	m1.insert("dix-sept");
	m1.insert("dix-huit");
	m1.insert("dix-neuf");
	m1.insert("vingt");
	m1.insert("vingt-un");
	m1.insert("vingt-deux");
	m1.insert("vingt-trois");
	m1.insert("vingt-quatre");
	m1.insert("vingt-cinq");
	m1.insert("vingt-six");
	m1.insert("vingt-sept");
	m1.insert("vingt-huit");
	m1.insert("vingt-neuf");
	m1.insert("trente");
	m1.insert("trente-un");
	m1.insert("trente-deux");
	cout << m1 << endl;

	return 0;
}
