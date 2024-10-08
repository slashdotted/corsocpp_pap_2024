#include <iostream>
#include "fraction.h"

using namespace std;

Fraction::Fraction()
    : Fraction{0,1} /* numerator{44} <--- non posso
                       più farlo perché numerator
                       è già stato inizializzato */
{
    //std::cout << "Fraction() " << this << std::endl;
    // Fraction(0,1); // è un altro oggetto!
}

Fraction::Fraction(int n, int d)
    : numerator{n}, denominator{d} // init-list
{
    //std::cout << "Fraction(int,int) " << this << std::endl;
    if (denominator == 0) {
        // ...
    }
    // l'oggetto è già inizializzato
    // print(*this);
}

/*
int Fraction::num() const {
    return numerator;
}

void Fraction::num(int value) {
    numerator = value;
}*/

int Fraction::den() const
{
    return denominator;
}

void Fraction::den(int value)
{
    denominator = value;
}

double Fraction::to_double() const
{
    return (double) numerator / denominator;
}

Fraction Fraction::operator+(Fraction o)
{
    o += *this;
    return o;
}

Fraction &Fraction::operator +=(const Fraction &o)
{
    int temp_numerator { o.numerator * denominator };
    denominator *= o.denominator;
    numerator *= o.denominator;
    numerator += temp_numerator;
    return *this;
}

// prefix
Fraction &Fraction::operator++()
{
    return *this += 1;
}

// postfix
Fraction Fraction::operator++(int)
{
    Fraction t{*this};
    *this += 1;
    return t;
}

/*Fraction &Fraction::operator -=(const Fraction &o)
{
    int temp_numerator { o.numerator * denominator };
    denominator *= o.denominator;
    numerator *= o.denominator;
    numerator -= temp_numerator;
    return *this;
}*/



/*Fraction::operator double() const
{
    //return to_double();
    return (double) numerator / denominator;
}*/

void print(const Fraction& f)
{
    cout << f.num() << "/" <<
         f.den() << endl;
}
