#include <iostream>

struct A
{
    A(int i = 0)
        : m_i{new int{i}}
    {}
    A(const A &o)
        : m_i{new int{*o.m_i}}
    {
        std::cout << "A(const A& o)\n";
    }
    A &operator=(const A &o)
    {
        std::cout << "A& operator=(const A& o)\n";
        *m_i = *o.m_i;
        return *this;
    }
    ~A() {
        delete m_i;
    }
    int value() const { return *m_i; }

private:
    int *m_i;
};


struct B : A {
    // Note: we are using A(d) because A{d} would fail due to a
    // narrowing conversion
    B(double d=3.14) : A(d), m_d{new double{d}} {}
    B(const B& o) : A{o}, m_d{new double{*o.m_d}} {
        std::cout << "B(const B& o)\n";
    }
    B& operator=(const B& o) {
        A::operator=(o);
        std::cout << "B& operator=(const B& o)\n";
        *m_d = *o.m_d;
        return *this;
    }
    ~B() {
        delete m_d;
    }
private:
    double* m_d;
};

void foo(B x)
{
    std::cout << x.value() << '\n';
}

int main() {
    B x;
    B z{5};
    z = x;
    std::cout << z.value() << '\n';
    std::cout << x.value() << '\n';
}
