// Gamal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ѕрограмма реализующа€ шифрование Ёль гомал€ согласно формуле

#include <iostream>
#include <ctime>

using namespace std;

unsigned long long mod(unsigned long long res_pow, unsigned long long mod)
{
	return res_pow - ((res_pow / mod) * mod);
}

int main()
{
	setlocale(0, "rus");
	cout << "Ўифр Ёль-√амал€" << endl;
	unsigned long long m, Cb, p, db, g, r, k, e;
	srand(time(NULL));


	p = 30803;
	cout << "p = " << p << endl;

	g = 2;
	cout << "g = " << g << endl;

	Cb = rand();
	cout << "Cb = " << Cb << endl;
	
	k = rand();
	cout << "k = " << k << endl;

	m = rand();
	cout << "m = " << m << endl;

	db = mod(pow(m, Cb), p);
	cout << "db = " << db << endl;
	
	r = mod(pow(g, k), p);
	cout << "r = " << r << endl;

	e = mod(m * db, p);
	cout << "e = " << e << endl;

	m = mod(r * pow(e, p - 1 - e), p);
	cout << "m = " << m << endl;

	
	return 0;

}

