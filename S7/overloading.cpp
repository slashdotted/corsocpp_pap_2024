#include <iostream>
using namespace std;
class Example {
public:
    void f(double x) // overloading of the f method
    {
        cout << "f(double x)" << endl;
    }

    void f(int x) // overloading of the f method
    {
        cout << "f(int x)" << endl;
    }

    Example& operator+=(int) // overloading of an operator
    {
        return *this;
    }

    int value()
    {
        return m_value;
    }

    void value(int v)
    {
        m_value = v;
    }

private:
    int m_value;
};

void foo()
{
}

void foo(int)   // overloading of a function
{
}

void foo(int,int)   // overloading of a function
{
}

void bar()
{
}

void bar_int(int)
{
}

void baz()
{
}

int main()
{
    Example e;
    e.f(3.2);
    e.f(3);
    e += 3;
}
