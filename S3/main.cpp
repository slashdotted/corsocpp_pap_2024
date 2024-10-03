#include "fraction.h"
#include <iostream>

void foo(const Fraction& g)
{
    print(g);
}

void bar(double d)
{
    std::cout << "Bar: " << d << std::endl;
}

int main()
{
    Fraction f1{2,3};
    print(f1);
    f1.num(7);
    f1.den(3);
    print(f1);

    Fraction* f2{new Fraction{1,2}};
    print(*f2);
    f2->num(3);
    f2->den(4);
    print(*f2);
    delete f2;

    Fraction{0,1};
    Fraction f3;
    print(f3);

    f1 = f3;
    f1 = 33; // f1 = Fraction{33};
    f1 = Fraction{33, 5};
    print(f1);
    foo(77);
    foo(3.14);
    bar(f1.to_double());
    bar(f1); // operatore di conversione a double
}
