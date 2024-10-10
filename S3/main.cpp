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

Fraction & operator -=(Fraction& a, const Fraction &o)
{
    int temp_numerator { o.num() * a.den() };
    a.den(a.den() * o.den());
    a.num(a.num() * o.den());
    a.num(a.num() - temp_numerator);
    return a;
}

Fraction operator-(Fraction a, const Fraction& b)
{
    a -= b;
    return a;
}

Fraction operator-(const Fraction& a)
{
    //return Fraction{- a.num(), a.den()};
    return {- a.num(), a.den()};
}

Fraction& operator--(Fraction& a)
{
    return a -= 1;
}

Fraction operator--(Fraction& a, int)
{
    Fraction t{a};
    a -= 1;
    return t;
}

std::ostream& operator<<(std::ostream& o, const Fraction& f)
{
    o << f.num() << "/" << f.den();
    return o;
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

    f1 += f3;
    f1.operator+=(f3);
    f1 += 8; // f1 += Fraction{8}
    f1.operator+=(8);
    //f1.operator-=(5);
    f1 = operator-=(f1,5);
    std::cout << (f1 -= 2).den();
    f1 -= f3;

    f1 + f3;
    f1 + 8;
    //8 + f1;

    f1 - f3;
    f1 - 8;
    8 - f1;
    foo(-f1);

    auto x = -f1+f3-5+2+f1;

    ++f1;
    f1++;

    --f1;
    f1--;


    std::cout << f1;
    std::cout << "Frazione:" << f1 << std::endl;


    //bar(f1); // operatore di conversione a double
}
