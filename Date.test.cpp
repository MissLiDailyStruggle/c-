#include "Date.h"
#include <iostream>

using namespace std;

void testDate()
{
	Date d1(1998, 05, 04);
	Date d2(d1);
	Date d3(2000, 05, 04);
	Date d4;
	d4 = d3;

	d1.print();
	d2.print();
	d3.print();
	d4.print();

	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 < d3) << endl;
	cout << (d1 > d3) << endl;
	cout << (d1 <= d3) << endl;
	cout << (d1 >= d3) << endl;
	
	//Date d5 = d1 + 100;
	//d5.print();
	Date d5 = d1.operator+(100);
	d5.print();

	Date d6 = d5 - 365;
	d6.print();

	d6 += 100;
	d6.print();

	d6 -= 100;
	d6.print();

	cout << d5 - d1 << endl;

	//Date d7 = ++d1;
	Date d7 = d1.operator++();
	d7.print();
	Date d8 = d2.operator++(0);
	d8.print();
}

int main()
{
	testDate();
	system("pause");
	return 0; 
}