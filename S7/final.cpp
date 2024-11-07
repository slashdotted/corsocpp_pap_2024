class FinalBase final {
};

/* Error: cannot inherit from a final base class */
/*class Derived : public FinalBase
{
};*/


class SuperBase {
public:
    // Note: final only works for polymorphic methods
    virtual void f() {}
};

class Base : public SuperBase {
public:
    // Note: final only works for polymorphic methods
    void f() final override {}
};

class Derived : public Base {
public:
    //void f() {} // Error: cannot override final virtual method
};

int main()
{
    Derived d;
    Base& b{d};
    b.f();
}
