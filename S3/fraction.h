#include <string>

class Fraction {
public:
    Fraction();

    // Un costruttore
    // che (tipicamente) accetta un solo
    // parametro di tipo X
    // diventa automaticamente / implicitamente
    // un costruttore di conversione
    // da X a (in questo caso) Fraction
    // Posso obbligare l'uso di conversioni
    // esplicite con 'explicit'
    /*explicit*/ Fraction(int n, int d = 1);

    // visibilità public
    //int num() const;
    //void num(int value);

    // Inline
    int num() const
    {
        return numerator;
    }

    void num(int value)
    {
        numerator = value;
    }

    int den() const;
    void den(int value);

    double to_double() const;

    operator double() const;

protected:
    // visibilità protected
private:
    // visibilità private
    int numerator{42}, denominator{1};
};

void print(const Fraction& f);
