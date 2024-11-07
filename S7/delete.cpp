class NonCopyableExample {
public:
    NonCopyableExample() = default;

    void oops()
    {
        NonCopyableExample k;
        k = *this; // A copy has been made here!
        bar(k);  // A copy has been made here!
    }
private:
    NonCopyableExample(const NonCopyableExample&) {}
    NonCopyableExample& operator=(const
                                  NonCopyableExample&)
    {
        return *this;
    }

    void bar(NonCopyableExample)
    {

    }
};





class ReallyNonCopyableExample {
public:
    ReallyNonCopyableExample() = default;
    ReallyNonCopyableExample(const ReallyNonCopyableExample&) = delete;
    ReallyNonCopyableExample& operator=(const ReallyNonCopyableExample&)
        = delete;

    void oops()
    {
        ReallyNonCopyableExample k;
        // k = *this; // Error: no copy allowed
        // bar(k);  // Error: no copy allowed
    }
private:
    void bar(ReallyNonCopyableExample)
    {

    }
};

void foo(NonCopyableExample) {}
void foo(ReallyNonCopyableExample) {}

int main()
{
    NonCopyableExample e, f;
    //e = f; // Error: copy assignment operator is private
    //foo(e); // Error: copy constructor is private
    e.oops(); // ...

    ReallyNonCopyableExample e1, f1;
    /*e1 = f1; // Error: copy assignment operator is deleted
    foo(e1); // Error: copy constructor is deleted
    e1.oops(); // ... */
}
