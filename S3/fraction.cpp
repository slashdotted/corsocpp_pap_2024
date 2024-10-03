#include <iostream>
#include "fraction.h"

using namespace std;

void print(const Fraction& f) {
	cout << f.numerator << "/" <<
	f.denominator << endl;
}

int main() {
	Fraction f1;
	f1.numerator = 2;
	f1.denominator = 3;
	print(f1);
	f1.numerator = 7;
	f1.denominator = 3;
	print(f1);
}
