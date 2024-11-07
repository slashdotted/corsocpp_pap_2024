#include <iostream>
using namespace std;

class SuperBase {
public:
    virtual void f(std::string x)
    {
        cout << "SuperBase::f(std::string x)" << endl;
    }
};

class Base : public SuperBase {
public:
    using SuperBase::f;

    virtual void f(double x)
    {
        cout << "Base::f(double x)" << endl;
    }
};

class Derived : public Base {
public:
    /*void f(double x) override
    {
        //cout << "Base::f(double x)" << endl;
        Base::f(x);
    }*/
    using Base::f;

    void f(int x) // What is this?
    {
        cout << "Derived::f(int x)" << endl;
    }
};

int main()
{
    Derived e;
    //e.Base::f(3.2);
    e.f(3.2);
    e.f(3);
    e.f("hello");
}
